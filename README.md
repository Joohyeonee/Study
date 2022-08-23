# Study

## linux 명령어 정리
- 파일 복사 : (보내는 경로에서) cp [파일이름] [받는 경로]
- 폴더 복사 : (보내는 경로에서) cp -r [폴더이름] [받는 경로]
- 권한 변경 : sudo - i(root로 변경) <--> su [username](user로 변경) 
- 폴더 삭제 : rm -rf [폴더 경로] (Permission denied 뜨면 root로 변경 뒤 sudo rm -rf [폴더경로]
- 서버 상태 보기 : top
- 디스크 용량 확인 : df -h
- 파일 조회 : cat [파일이름]


## docker 명령어 정리
- 터미널에서 컨테이너 접속 : docker attach [컨테이너명]
- 컨테이너를 이미지로 만들기 : docker commit [현재 컨테이너명] [만들 이미지명]
- 실행된 프로세스에 접근 : docker exec -it [컨테이너명] /bin/bash
- 백그라운드에서 컨테이너 실행 : docker run -d
- 유사 터미널(실제 터미널 x) 할당 : docker run -t
- 볼륨 마운트 : -v [호스트 경로]:[컨테이너 경로]
> -v /home/jhlee/workspace/metadata:/workspace/metadata_jhlee

## Python 정리
1. json 로드
 - json.loads() : string을 가져올 때
 ```
 data = {"info:"01", "file_name":"2020-06-25.mp4"}
 j = json.loads(data)
 ```
 - json.load() : json 파일을 가져올 때
 ```
 with open("jsondata.json", "w", encoding="utf-8") as json_file:
 j = json.load(json_file)
 ```
 - json_object.get() : 중첩된 object의 value를 읽을 때
 ```
 json_file = open(path, 'r', encoding = 'utf-8')
 json_object = json.loads(json_file.reaad())
 value = json_object.get("key")
 ```
 
## Pytorch 개념 정리
1. Tensor
 - 배열, 행렬과 유사한 자료구조로, 연산을 가속화하기 위해 사용
 - 대부분 C++, CUDA(cuDNN)로 만들어짐
 - 1차원 배열로 저장 공간에 저장됨
 - Dataset을 통해 pytorch 표준 텐서로 변환 가능
 - Dataloader를 통해 배치 단위 데이터 로드 지원
 - torch.nn.DataParallel을 통해 GPGPU 지원
 - Define and Run 방식 : 연산 그래프를 만듦과 동시에 값 할당
