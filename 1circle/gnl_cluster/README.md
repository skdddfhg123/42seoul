## 선행 지식

[파일 디스크립터(FD)](https://www.notion.so/FD-2a9d67195942438e9145be9b5d4b08ba)

[C언어 파일 읽기 함수](https://www.notion.so/C-786c1cf657204eb4903ae0b47e85f5f1)

[Static 변수 (정적 변수)](https://www.notion.so/Static-f131ad97896241e1958496a80336608a)

[gcc -D 옵션](https://www.notion.so/gcc-D-8fb52525ff3c4db1823bd31583cc00db)

## 과제의 목표

- 파일 디스크립터로부터 읽어 온 하나의 라인을 반환하는 함수 작성
- GNL 함수를 반복문 안에서 호출 시 FD에서 사용할 수 있는 텍스트를 EOF가 올 때까지 한번에 한줄 씩 읽을 수 있어야 함
- GNL 함수를 처음 호출했을 때 지정한 버퍼의 크기가 매우 커서 한 번에 파일을 끝까지 읽었다 하더라도, 두 번째 호출했을 때는 두번 째 줄부터 읽기를 시작해야 함
- file, redirection, stdin 으로부터 읽었을 때 함수가 제대로 작동해야 함
- gcc -d플래그로 받은 BUFFER_SIZE가 1일 때도, 9999일 때에도, 10000000일 때에도 함수가 제대로 작동해야 함 (-D BUFFER_SIZE = xx 플래그를 붙여서 컴파일 해야 함.)
- Single Static Variable로 get_next_line 성공하기

## 진행 과정

1. 파일은 읽을 임시 버퍼를 만든다.

`char str_buf[BUFFER_SIZE];`

1. 읽은 버퍼를 저장할 공간을 만든다.

`static char *backup;`

1. 이전에 받아둔 문자열에 개행 문자가 있는지 확인한다.
2. read함수를 사용해 `BUFFER_SIZE`만큼 읽어온다.
3. 2번에서 만든 저장 공간 `backup`에 `strjoin`을 사용하여 저장한다.
4. 해당 문자열에서 개행 문자가 있는지 확인한다.
    1. 있을 시, 해당 문자열을 조작하고 1을 반환한다.
    2. 없을 시, 4번으로 돌아간다.
5. 개행문자가 있는 `backup`을 개행문자 전과 후로 잘라, 개행문자 전까지는 line에 주고, 개행문자 후는 다시 static변수 `backup`에 넣는다. 만약, read함수가 `EOF`를 만나면, 저장되어 있는 문자열 확인 후 0을 반환한다.

코드

- get_next_line.c
    
    ```c
    
    #include "get_next_line.h"
    
    static char	*ft_getline(char	*backup)
    {
    	char	*line;
    	size_t	i;
    
    	if (!*backup)
    		return (NULL);
    	i = 0;
    	while (backup[i] && backup[i] != '\n')
    		i++;
    	line = (char *)malloc(sizeof(char) * (i + 2));
    	if (!line)
    		return (NULL);
    	ft_strlcpy(line, backup, i + 1);
    	if (backup[i] == '\n')
    		line[i++] = '\n';
    	line[i] = '\0';
    	return (line);
    }
    
    static char	*remove_read_line(char *backup)
    {
    	int		i;
    	int		j;
    	char	*new_backup;
    
    	i = 0;
    	while (backup[i] && backup[i] != '\n')
    		i++;
    	if (!backup[i])
    	{
    		free(backup);
    		return (NULL);
    	}
    	new_backup = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
    	if (!new_backup)
    		return (NULL);
    	i++;
    	j = 0;
    	while (backup[i])
    		new_backup[j++] = backup[i++];
    	new_backup[j] = '\0';
    	free(backup);
    	return (new_backup);
    }
    
    char	*get_next_line(int fd)
    {
    	static char	*backup;
    	char		*buffer;
    	char		*line;
    	ssize_t		read_size;
    
    	if (fd < 0 || BUFFER_SIZE < 1)
    		return (NULL);
    	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    	if (!buffer)
    		return (NULL);
    	read_size = 1;
    	while (read_size > 0 && !ft_strchr(backup, '\n'))
    	{
    		read_size = read(fd, buffer, BUFFER_SIZE);
    		if (read_size < 0)
    			break ;
    		buffer[read_size] = '\0';
    		backup = ft_strjoin(backup, buffer);
    	}
    	free(buffer);
    	if (read_size < 0)
    		return (NULL);
    	line = ft_getline(backup);
    	backup = remove_read_line(backup);
    	return (line);
    }
    ```
    
- main.c
    
    ```c
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    
    int	main(void)
    {
    	int		fd;
    	char	*line;
    
    	fd = open("test.txt", O_RDONLY);
    	fd1 = open("test.txt", O_RDONLY);
    	// while (get_next_line(fd) != 0)
    	// {
    	// 	line = get_next_line(fd);
    	// 	printf("%s", line);
    	// }
    	line = get_next_line(fd);
    	printf("%s", line);
    	line = get_next_line(fd1);
    	printf("%s", line);
    	line = get_next_line(fd);
    	printf("%s", line);
    	close(fd);
    	return (0);
    }
    ```
