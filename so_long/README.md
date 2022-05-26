# Keyword
- 나만의 2d 게임을 만들어보자!

## x-window
- 그래픽 출력을 위해 클라이언트 서버 모델을 사용하며, TCP/IP 네트워크 기반의 X 프로토콜로 통신을 한다. 간단하게, 클라이언트가 무언가 그래픽적인 요구를 X 서버로 전달하면, X 서버가 요청을 처리하여 클라이언트로 반환해 준다. 이러한 구조를 가지게된 이유는 한 컴퓨터에 모니터, 키보드를 여럿 붙이고 동시에 이용하던 시절에 작성된 프로그램이기 때문이다. 이 구조 덕에 다른 시스템에 설치되어 있는 프로그램을 내 시스템에 X 윈도우를 통해 원격으로 출력할 수 있다.

## color integer standard
  - 0xTTRRGGBB (t : transparency, r : red, g : green, b : blue)
  - 4bit + 4bit = 1byte => TT = 1byte, RR, GG, BB also

## mlx
- cocoa, x-window에 대해 몰라도 쓸 수 있게 하는 라이브러리
- macos는 화면에 대한 그래픽 접근을 관리하기 때문에 application에 깔려 있는 graphical 프레임워크에 등록해야 한다.
  - gcc -L./ -lmlx `-framework OpenGL -framework Appkit` main.c
- DLL ... ?

## mlx's functions
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

## exit
- exit(0)
  - 일반 종료
- write(1, buf, length)
  - 일반 출력
- exit(1)
  - 에러 종료
- write(2, buf, length)
  - 에러 출력