export interface ProcProperties {
    cmd: string;
    numprocs: number;
    umask: string;
    workingdir: string;
    autostart: boolean;
    autorestart: string;
    exitcodes?: (number)[] | null;
    startretries: number;
    starttime: number;
    stopsignal: string;
    stoptime: number;
    stdout: string;
    stderr: string;
}