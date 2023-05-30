## 선행 지식

[MiniLibX](https://www.notion.so/MiniLibX-3d984989344642ceadb81d7a7b41ad59)

## 과제의 목표

- MiniLibX를 활용한 간단한 게임 만들기
- 과제에서는 다음과 같은 제한 사항을 두었다
    1. `minilibx` 라이브러리를 사용해야 한다.
    2. 맵은 "벽", "아이템", "빈 공간"의 세 요소로 구성되어야 한다.
    3. 플레이어는 맵에 표시된 모든 아이템을 획득한 후 탈출구로 나가야 한다.
    4. 플레이어가 움직일 때 마다 쉘에 움직인 횟수가 표시되어야 한다.
    5. 플레이어는 위(`w`), 아래(`s`), 오른쪽(`d`), 왼쪽(`a`)으로 움직일 수 있다.
    6. 플레이어는 벽을 넘을 수 없다.
    7. `esc키` 또는 윈도우의 `x버튼`을 누르면 프로그램이 종료된다.
    8. 프로그램은 인자로 `.ber` 형식의 맵을 받는다.
    9. 맵 파일은 다음의 요소들로만 구성된다.`0` : 빈 공간`1` : 벽`C` : 아이템`E` : 탈출구`P` : 플레이어의 시작 위치
    10. 맵은 벽으로 둘러싸여 있어야 한다.
    11. 맵에는 최소 하나의 탈출구와 아이템이 있어야 하며, 하나의 플레이어 시작점이 있어야 한다.
    12. 맵은 사각형이어야 한다.
    13. 프로그램에 오류가 생기면 프로그램을 종료시키고 `"Error/n"`라는 문구와 명시적인 오류 메시지를 출력해야 한다.
    

## 간단한 코드 설명 및 실행

- mian 함수
    
    ```c
    int	main(int argc, char **argv)
    {
    	t_game	*game;
    
    	if (!make_map(argc, argv, &game)) // 맵 파일 체크
    		return (1);
    	initialization(game); // 초기화
    	insert_player(game); // Map에서 플레이어의 위치를 찾아 변수 저장
    	insert_window(game); // Mlx 윈도우 설정
    	insert_image(game); // xpm파일 변수 저장
    	draw_map(game); // 맵 그리기
    	loop(game); // 게임이 끝날 때 까지 반복
    }
    ```
    

main함수의 로직은 다음과 같다.

1. 맵이 정당한 파일인지 파악을 한다. (.ber으로 끝나는 체크)
2. 간단한 오류를 체크하고 정상적인 파일로 파악이 되었을 시 안에서 사용 될 변수들을 초기화를 한다.
3. Map파일에서 플레이어의 위치를 찾아 변수에 저장을 한다.
4. xpm파일을 간단히 사용하기 위해 변수에 따로 저장을 한다.
5. 이제 mlx함수들을 사용해 게임이 완료 되거나 강제로 종료 될 때까지 loop함수를 반복한다.
- loop함수
    
    ```
    void	loop(t_game *game)
    {
    	mlx_loop_hook(game->mlx, &draw_map, game); // loop hook 을 통해 draw map 함수를 반복해서 호출
    	mlx_hook(game->win, KEY_PRESS, 0, &key_press, game); // key press 이벤트가 발생했을 때 key_press 함수 실행
    	mlx_hook(game->win, 17, 0, &exit_game, game); // 17은 red_sign으로 윈도우 왼쪽 위 x버튼을 눌렀을 때 해당 이벤트 실행
    	mlx_clear_window(game->mlx, game->win);
    	mlx_loop(game->mlx);
    }
    ```
    

실행 화면

![Screen Shot 2023-05-30 at 11.29.55 AM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a39f34bb-2e8d-4f86-8f76-7ba69cff9806/Screen_Shot_2023-05-30_at_11.29.55_AM.png)

터미널에는 현재 플레이의 좌표 값과 이동한 걸음의 수를 표기하고 있다.

잼을 전부 먹고 도착 지점에 가면 끝나게 된다.
