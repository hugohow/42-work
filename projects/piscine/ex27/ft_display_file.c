#include "ft_prot.h"

int	main(int argc, char **argv)
{
	if (ft_check_param_num(argc))
		ft_read_file(argv[1]);
	return (0);
}
