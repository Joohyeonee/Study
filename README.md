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
- 컨테이너 실행 : docker start [컨테이너명]
- 컨테이너 종료 : docker stop [컨테이너명]
- 터미널에서 컨테이너 접속 : docker attach [컨테이너명] -> attach의 bash가 고장나는 경우 작동되지 않을 수 있음
- 컨테이너를 이미지로 만들기 : docker commit [현재 컨테이너명] [만들 이미지명]
- 실행된 프로세스에 접근 : docker exec -it [컨테이너명] /bin/bash -> 되도록이면 이걸로 사용
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

2. 자료형
- Dictionary : {key : value} 쌍을 가지는 자료형 ex> {"gender" : "male"}
>> - 추가 : 딕셔너리명["key"] = "value"
>> - 삭제 : del 딕셔너리명["key"]
>> - key값만 리스트로 불러오기 : list(딕셔너리명.keys())
>> - key로 value 얻기 : 딕셔너리명.get("key")
>> - key값이 중복되면 하나를 제외한 나머지가 무시됨
 
## Pytorch 개념 정리
1. Tensor
 - 배열, 행렬과 유사한 자료구조로, 연산을 가속화하기 위해 사용
 - 대부분 C++, CUDA(cuDNN)로 만들어짐
 - 1차원 배열로 저장 공간에 저장됨
 - Dataset을 통해 pytorch 표준 텐서로 변환 가능
 - Dataloader를 통해 배치 단위 데이터 로드 지원
 - torch.nn.DataParallel을 통해 GPGPU 지원
 - Define and Run 방식 : 연산 그래프를 만듦과 동시에 값 할당
 
## pandas 사용법 정리
 - dataframe 값을 리스트로 저장 : df.values.tolist()
 - 기존 csv 이어쓰기 : to_csv([저장할 파일명], mode = 'a', header = 'False')
 ```
 data_df = pd.DataFrame(filename_output)
    if not os.path.exists('before_decoding.csv'):
        data_df.to_csv('before_decoding.csv', index = False, mode = 'w', encoding = 'utf-8')
    else:
        data_df.to_csv('before_decoding.csv', index = False, mode = 'a', encoding = 'utf-8', header = False)
 ```
 
## OpenCV 함수 정리
 - 이미지 읽기 : img = cv2.imread(filename)
 - 이미지 띄우기 : cv2.imshow(filename, cv2.IMREAD_COLOR)
 - 이미지 파일로 저장하기 : cv2.imwrite(filename, img)
 - 이미지 크기 변경 : img_res = cv2.resize(img, (width, height))
 - 비디오 프레임 캡쳐 : cap = cv2.VideoCapture(filepath)
 - 속성값
 >> - cv2.CAP_PROP_FRAME_WIDTH : 프레임 폭
 >> - cv2.CAP_PROP_FRAME_HEIGHT : 프레임 높이
 >> - cv2.CAP_PROP_FPS : 초당 프레임 수
 >> - cv2.CAP_PROP_FRAME_COUNT : video의 전체 프레임 개수
