# Keyword

- x-window

- color integer standard
    - 0xTTRRGGBB (t : transparency, r : red, g : green, b : blue)
    - 4bit + 4bit = 1byte => TT = 1byte, RR, GG, BB also

## mlx
- cocoa, x-window에 대해 몰라도 쓸 수 있게 하는 라이브러리
- macos는 화면에 대한 그래픽 접근을 관리하기 때문에 application에 깔려 있는 graphical 프레임워크에 등록해야 한다.
    - gcc -L./ -lmlx `-framework OpenGL -framwork Appkit` main.c
- DLL ... ?

### mlx's functions

- mlx_init
    - 모든 함수에 접근할 수 있게 한다.
    - 그래픽 시스템에 connection을 만든다.
- mlx_new_window
    - 창을 불러오는 함수.
- mlx_new_image
    - img 저장하는 함수
- mlx_get_data_addr
    - img 불러오는 함수 (생성된 이미지의 정보 반환)
    - 리틀엔디안 0, 빅엔디안 1
- mlx_get_color_value
    - 이미지 내부 색상 지정
- mlx_xpm_to_image
    - xpm에 맞는 새 이미지 지정
- mlx_png_file_to_image
    - png에 맞는 새 이미지 지정
- mlx_pixel_put
    - pixel 렌더링 함수
- mlx_destroy_image
    - 이미지 삭제
- mlx_put_image_to_window
    - img 렌더링 함수
- mlx_key_hook
    - key binding
- mlx_destroy_window
    - 화면 없애기
- mlx_loop
    - kind of event listener
- mlx_key_hook
- mlx_mouse_hook
- mlx_expose_hook
- mlx_loop_hook
    - 아무 이벤트도 일어나지 않을 때 콜백 호출