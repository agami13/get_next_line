// #include <stdio.h>
// int main()
// {
// 	int fd[3];
// 	int i;
// 	char *rs;

// 	i = 0;
// 	fd[0] = open("file.txt", O_RDONLY);
// 	fd[1] = open("file2.txt", O_RDONLY);
// 	fd[2] = open("file3.txt", O_RDONLY);
// 	while (i < 3)
// 	{
// 		printf("\n\n-------------------------------------------\n\n");
// 		rs = get_next_line(fd[0]);
// 		printf("file.txt : %s", rs);
// 		free(rs);
// 		printf("\n\n-------------------------------------------\n\n");
// 		rs = get_next_line(fd[1]);
// 		printf("file1.txt : %s", rs);
// 		free(rs);
// 		printf("\n\n-------------------------------------------\n\n");
// 		rs = get_next_line(fd[2]);
// 		printf("file2.txt : %s", rs);
// 		free(rs);
// 		i++;
// 	}
// 	printf("\n\n-------------------------------------------\n\n");
// 	close (fd[0]);
// 	close (fd[1]);
// 	close (fd[2]);
// }
