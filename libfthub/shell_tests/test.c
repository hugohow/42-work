/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:08:11 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/25 13:53:37 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h" /* compile with -I./ */

#include <assert.h>

int main(void)
{
	printf("-------------Test ft_str_separate-------------\n");
	char dst[999];
	char **list;

	list = ft_str_separate(NULL, '/');
  	printf("\033[32mCheck basic %s \033[00m\n", NULL);
	assert(list == NULL);
	ft_memdel((void **)list);

	ft_strcpy(dst, "");
	list = ft_str_separate(dst, '/');
  	printf("\033[32mCheck basic %s \033[00m\n", dst);
	assert(ft_strcmp(list[0], "") == 0);
	assert(list[1]== 0);
	ft_memdel((void **)list);

	ft_strcpy(dst, "Hello");
	list = ft_str_separate(dst, '/');
  	printf("\033[32mCheck basic %s \033[00m\n", dst);
	assert(ft_strcmp(list[0], "Hello") == 0);
	assert(list[1]== 0);
	ft_memdel((void **)list);


	ft_strcpy(dst, "/");
	list = ft_str_separate(dst, '/');
  	printf("\033[32mCheck basic %s \033[00m\n", dst);
	assert(ft_strcmp(list[0], "") == 0);
	assert(list[1]== 0);
	ft_memdel((void **)list);

	ft_strcpy(dst, " / ");
	list = ft_str_separate(dst, '/');
  	printf("\033[32mCheck basic %s \033[00m\n", dst);
	assert(ft_strcmp(list[0], " ") == 0);
	assert(ft_strcmp(list[1], " ") == 0);
	assert(list[2]== 0);
	ft_memdel((void **)list);

	ft_strcpy(dst, "/ ");
	list = ft_str_separate(dst, '/');
  	printf("\033[32mCheck basic %s \033[00m\n", dst);
	assert(ft_strcmp(list[0], "") == 0);
	assert(ft_strcmp(list[1], " ") == 0);
	assert(list[2]== 0);
	ft_memdel((void **)list);

	ft_strcpy(dst, " /");
	list = ft_str_separate(dst, '/');
  	printf("\033[32mCheck basic %s \033[00m\n", dst);
	assert(ft_strcmp(list[0], " ") == 0);
	assert(ft_strcmp(list[1], "") == 0);
	assert(list[2]== 0);
	ft_memdel((void **)list);

	ft_strcpy(dst, " ///");
	list = ft_str_separate(dst, '/');
  	printf("\033[32mCheck basic %s \033[00m\n", dst);
	assert(ft_strcmp(list[0], " ") == 0);
	assert(ft_strcmp(list[1], "") == 0);
	assert(list[2]== 0);
	ft_memdel((void **)list);

	ft_strcpy(dst, "test/122/33");
	list = ft_str_separate(dst, '/');
  	printf("\033[32mCheck basic %s \033[00m\n", dst);
	assert(ft_strcmp(list[0], "test") == 0);
	assert(ft_strcmp(list[1], "122") == 0);
	assert(ft_strcmp(list[2], "33") == 0);
	assert(list[3]== 0);
	ft_memdel((void **)list);

	ft_strcpy(dst, "/test/122/33");
	list = ft_str_separate(dst, '/');
  	printf("\033[32mCheck basic %s \033[00m\n", dst);
	assert(ft_strcmp(list[0], "") == 0);
	assert(ft_strcmp(list[1], "test") == 0);
	assert(ft_strcmp(list[2], "122") == 0);
	assert(ft_strcmp(list[3], "33") == 0);
	assert(list[4]== 0);
	ft_memdel((void **)list);

	
	ft_strcpy(dst, "//test/122/33");
	list = ft_str_separate(dst, '/');
  	printf("\033[32mCheck basic %s \033[00m\n", dst);
	assert(ft_strcmp(list[0], "") == 0);
	assert(ft_strcmp(list[1], "test") == 0);
	assert(ft_strcmp(list[2], "122") == 0);
	assert(ft_strcmp(list[3], "33") == 0);
	assert(list[4]== 0);
	ft_memdel((void **)list);

	ft_strcpy(dst, "/////test/122/33");
	list = ft_str_separate(dst, '/');
  	printf("\033[32mCheck basic %s \033[00m\n", dst);
	assert(ft_strcmp(list[0], "") == 0);
	assert(ft_strcmp(list[1], "test") == 0);
	assert(ft_strcmp(list[2], "122") == 0);
	assert(ft_strcmp(list[3], "33") == 0);
	assert(list[4]== 0);
	ft_memdel((void **)list);


	ft_strcpy(dst, "/////test/122/33/");
	list = ft_str_separate(dst, '/');
  	printf("\033[32mCheck basic %s \033[00m\n", dst);
	assert(ft_strcmp(list[0], "") == 0);
	assert(ft_strcmp(list[1], "test") == 0);
	assert(ft_strcmp(list[2], "122") == 0);
	assert(ft_strcmp(list[3], "33") == 0);
	assert(ft_strcmp(list[4], "") == 0);
	assert(list[5]== 0);
	ft_memdel((void **)list);


	ft_strcpy(dst, "/////test/122/33/////");
	list = ft_str_separate(dst, '/');
  	printf("\033[32mCheck basic %s \033[00m\n", dst);
	assert(ft_strcmp(list[0], "") == 0);
	assert(ft_strcmp(list[1], "test") == 0);
	assert(ft_strcmp(list[2], "122") == 0);
	assert(ft_strcmp(list[3], "33") == 0);
	assert(ft_strcmp(list[4], "") == 0);
	assert(list[5]== 0);
	ft_memdel((void **)list);


	ft_strcpy(dst, "/////test//122//33/////");
	list = ft_str_separate(dst, '/');
  	printf("\033[32mCheck basic %s \033[00m\n", dst);
	assert(ft_strcmp(list[0], "") == 0);
	assert(ft_strcmp(list[1], "test") == 0);
	assert(ft_strcmp(list[2], "122") == 0);
	assert(ft_strcmp(list[3], "33") == 0);
	assert(ft_strcmp(list[4], "") == 0);
	assert(list[5]== 0);
	ft_memdel((void **)list);


	printf("-------------Test ft_path_trim-------------\n");


	ft_strcpy(dst, "////bonjour/");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "/bonjour/") == 0);


	ft_strcpy(dst, "/./././bonjour/.");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "/bonjour") == 0);


	ft_strcpy(dst, "/./././bon/jour/.");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "/bon/jour") == 0);


	ft_strcpy(dst, "/./././bon/jour/..");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "/bon") == 0);


	ft_strcpy(dst, "/./././bon/jour/../..");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "/") == 0);


	ft_strcpy(dst, "hello");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "hello") == 0);

	ft_strcpy(dst, "/hello/");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "/hello/") == 0);

	ft_strcpy(dst, "//hello/");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "/hello/") == 0);


	ft_strcpy(dst, "//he/.//llo/");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "/he/llo/") == 0);


	ft_strcpy(dst, ".././..///he/.//llo/");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "he/llo/") == 0);


	ft_strcpy(dst, "/.././..///he/.//llo/");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "/he/llo/") == 0);



	ft_strcpy(dst, "/");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "/") == 0);


	ft_strcpy(dst, "/..");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "/") == 0);

	ft_strcpy(dst, "/../");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "/") == 0);

	ft_strcpy(dst, "/../../../.");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "/") == 0);


	ft_strcpy(dst, "/../../../Library");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "/Library") == 0);


	ft_strcpy(dst, "/../../../Library/..");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "/") == 0);



	ft_strcpy(dst, "/../../../Library/../..//..");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "/") == 0);


	ft_strcpy(dst, ".");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "") == 0);


	ft_strcpy(dst, "./libft");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "libft") == 0);


	ft_strcpy(dst, "./libft/..");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "") == 0);


	ft_strcpy(dst, "./a/libft/..");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "a") == 0);


	ft_strcpy(dst, "./a/libft/../..");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "") == 0);


	ft_strcpy(dst, "./a/libft/../..//P//A//D");
	printf("\033[32mCheck basic %s \033[00m\n", dst);
	printf("result : %s\n", ft_path_trim(dst));
	assert(ft_strcmp(ft_path_trim(dst), "P/A/D") == 0);
	// int i;

	// while (list[i])
	// {
	// 	printf("%s\n", list[i]);
	// 	i++;
	// }
	// assert(ft_strcmp(ft_strcat_r("Hello World", dst), "Hello Worldtest") == 0);

  	// printf("\033[32mCheck basic \033[00m\n");
	// assert(ft_strcmp(ft_strcat_r("\n", dst), "\nHello Worldtest") == 0);

  	// printf("\033[32m0 value \033[00m\n");
	// assert(ft_strcmp(ft_strcat_r("", dst), "\nHello Worldtest") == 0);

	return (0);
}
