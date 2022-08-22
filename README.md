# Study

## linux 명령어 정리
- 파일 복사 : (보내는 경로에서) cp [파일이름] [받는 경로]
- 폴더 복사 : (보내는 경로에서) cp -r [폴더이름] [받는 경로]
- 권한 변경 : sudo - i(root로 변경) <--> su [username](user로 변경) 
- 폴더 삭제 : rm -rf [폴더 경로] (Permission denied 뜨면 root로 변경 뒤 sudo rm -rf [폴더경로]
- 서버 상태 보기 : top
- 디스크 용량 확인 : df -h
- 파일 조회 : cat [파일이름]


##docker 명령어 정리
- 터미널에서 컨테이너 접속 : docker attach [컨테이너명]
- 컨테이너를 이미지로 만들기 : docker commit [현재 컨테이너명] [만들 이미지명]
- 실행된 프로세스에 접근 : docker exec -it [컨테이너명] /bin/bash
