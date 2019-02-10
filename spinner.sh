function display_spinner
{
    local PID=$1             # 1st argument: PID of the background process
    local TIMEOUT=$2         # 2st argument: Time out in seconds

    local DELAY=0.75         # Delay for each frame of the animation
    local FRAMES='|/-\'      # Each symbol is a frame of the animation

    # Calculate the maximum number of loops (time out)
    local -i MAX_LOOP
    MAX_LOOP=$(awk -v t=$TIMEOUT -v d=$DELAY 'BEGIN {printf "%d", t/d}')

    # Start the loop until the background process $PID has terminated
    while [ ! -z "$(ps a | awk '{print $1}' | grep $PID)" ];
    do
        # If the time out has been reached:
        # kill the process $PID and exit function
        if [ "$MAX_LOOP" -le 0 ]
        then
            kill $PID            # Call the builtin kill
            wait $! 2>/dev/null  # Wait for the killing process
            return               # Exit the function
        fi

        # Display the current frame and the time out
        printf " [%c] %-4d " "$FRAMES" "$MAX_LOOP"

        # Move the current frame at the end of $FRAMES
        local TMP=${FRAMES#?}
        FRAMES=$TMP${FRAMES%"$TMP"}

        # Wait during the delay and erase the current frame
        sleep $DELAY
        printf "\b\b\b\b\b\b\b\b\b\b"

        # Decrement the time out
        (( MAX_LOOP -= 1 ))

    done
}

(sleep 10) &           # Send a process to the background with '&'
                       # e.g.: (ft_ls -R /) &

display_spinner $! 60  # Call the spinner animation with:
                       # - 1st argument: the last PID
                       # - 2nd argument: time out in seconds