# Study

## linux 명령어 정리
- 파일 복사 : (보내는 경로에서) cp [파일이름] [받는 경로]
- 폴더 복사 : (보내는 경로에서) cp -r [폴더이름] [받는 경로]
- 권한 변경 : sudo - i(root로 변경) <--> su [username](user로 변경) 
- 폴더 삭제 : rm -rf [폴더 경로] (Permission denied 뜨면 root로 변경 뒤 sudo rm -rf [폴더경로]
- 서버 상태 보기 : top
- 디스크 용량 확인 : df -h
- 파일 조회 : cat [파일이름]
- 사용중인 포트 종료 : sudo lsof -t -i tcp:[포트번호] | xargs kill -9

## docker 명령어 정리
- 컨테이너 실행 : docker start [컨테이너명]
- 컨테이너 종료 : docker stop [컨테이너명]
- 터미널에서 컨테이너 접속 : docker attach [컨테이너명] -> attach의 bash가 고장나는 경우 작동되지 않을 수 있음
- 컨테이너를 이미지로 만들기 : docker commit [현재 컨테이너명] [만들 이미지명]
- 이미지 공유하기 : docker save -o [파일명.tar] [이미지명] / 공유된 이미지 사용 : docker load -i [파일명.tar]
- 실행된 프로세스에 접근 : docker exec -it [컨테이너명] /bin/bash -> 되도록이면 이걸로 사용
- 백그라운드에서 컨테이너 실행 : docker run -d
- 유사 터미널(실제 터미널 x) 할당 : docker run -t
- 볼륨 마운트 : docker run -it -v [호스트 경로]:[컨테이너 경로]
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
>> - list 중복 제거 : my_set = set(중복값이 있는 리스트명) my_list = list(my_set)
 
3. shallow copy vs deep copy
 - shallow copy : 원본 객체를 바탕으로 새로운 객체를 생성한 뒤 내부 필드의 참조에 대해서는 원본 객체와 같은 필드의 참조를 바라보는 형태
 - deep copy : 원본 객체의 타입을 바탕으로 새로운 객체를 생성한 뒤, 내부 필드가 참조하는 객체에 대해서도 새로운 객체를 만들어주는 방식
 ```
 #shallow
 import copy

 a = [1, 2, [3, 4]]
 b = copy.copy(a)

 b[2].append(5)

 print(b)
 -> [1, 2, [3, 4, 5]]
 print(a)
 -> [1, 2, [3, 4, 5]]
 ``` 
 ![shallow copy original](https://velog.velcdn.com/images%2Fkkamyang%2Fpost%2Ffcf0f80f-953e-4d92-bc05-909c39bce008%2Fimage.png)
 ![shallow copy copying](https://velog.velcdn.com/images%2Fkkamyang%2Fpost%2Fae990d20-b588-4de7-92ac-7b23f0d70f89%2Fimage.png)
 ![shallow copy result](https://velog.velcdn.com/images%2Fkkamyang%2Fpost%2Fb29011e0-abdd-4072-89fb-84d6d73eff25%2Fimage.png)
 
 ```
 #deep copy
 import copy

 a = [1, 2, [3, 4]]
 b = copy.deepcopy(a)

 b[2].append(5)

 print(b)
 -> [1, 2, [3, 4, 5]]
 print(a)
 -> [1, 2, [3, 4]]
 ```
 ![deep copy](https://velog.velcdn.com/images%2Fkkamyang%2Fpost%2F965f60f9-27b7-4164-8310-6174d81fd4b7%2Fimage.png)
 
 ```
 //Shallow copy - java
 @NoArgsConstructor
 @AllArgsConstructor
 @Getter
 public class Menu implements Copyable<Menu> {

   private String name;
   private int price;
   private Recipe recipe;

   @Override
   public Menu shallowCopy(Menu menu) {
     Menu copyMenu = new Menu(menu.getName(), menu.getPrice(), menu.getRecipe());
     return copyMenu;
   }
 }
 
 //Deep copy - java
 @NoArgsConstructor
 @AllArgsConstructor
 @Getter
 @Setter
 public class Menu implements Copyable<Menu> {

   private String name;
   private int price;
   private Recipe recipe;

   @Override
   public Menu deepCopy(Menu menu) {
     Menu copyMenu = new Menu();
     copyMenu.setName(new String(menu.getName));
     copyMenu.setPrice(menu.getPrice());
     copyMenu.setRecipe(Recipe.deepCopy(menu.getRecipe));
     return copyMenu;
   }
 }
 ```
 
 4. string 쪼개기 : split(구분자) 함수 사용 / split(".", maxsplit = 3) #.을 구분자로 하여 쪼개고, 최대 3개까지 쪼갬
 
 
## Python 라이브러리 정리
1. Tensor
 - 배열, 행렬과 유사한 자료구조로, 연산을 가속화하기 위해 사용
 - 대부분 C++, CUDA(cuDNN)로 만들어짐
 - 1차원 배열로 저장 공간에 저장됨
 - Dataset을 통해 pytorch 표준 텐서로 변환 가능
 - Dataloader를 통해 배치 단위 데이터 로드 지원
 - torch.nn.DataParallel을 통해 GPGPU 지원
 - Define and Run 방식 : 연산 그래프를 만듦과 동시에 값 할당
 
2. Pandas
 - dataframe 값을 리스트로 저장 : df.values.tolist()
 - 기존 csv 이어쓰기 : to_csv([저장할 파일명], mode = 'a', header = 'False')
 ```
 data_df = pd.DataFrame(filename_output)
    if not os.path.exists('before_decoding.csv'):
        data_df.to_csv('before_decoding.csv', index = False, mode = 'w', encoding = 'utf-8')
    else:
        data_df.to_csv('before_decoding.csv', index = False, mode = 'a', encoding = 'utf-8', header = False)
 ```
 - 특정 조건을 만족하는 값 저장 : df[df['컬럼명'] == '조건'] 
 - df.concat() : dataframe으로 구성된 리스트들을 한번에 다 합쳐서 새로운 dataframe을 만들어주는 함수
 - df.append() : 각 dataframe의 내부 method로 같은 column을 가진 dataframe을 끝에 붙여주는 함수
 - concat vs append : concat의 속도가 더 빠름
 - 중복값만 찾기 : df[df.duplicated()]
 - 중복값 제거 : df[~df.duplicated()]
 
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
 
 ## C++ Smart Pointer
  >> - Pointer 메모리 해제 : 사용되지 않는 리소스를 자동으로 해제하는 Garbage Collecter 기능이 없기 때문에 메모리 누수 발생
  >> - smart pointer : 가리키고 있는 대상에 대해 소멸자가 자동으로 delete를 호출하도록 설계된 객체
  - unique_ptr : 이미 해제된 메모리를 다시 참조하는 경우 이미 소멸된 객체를 소멸하려고 할 때 메모리 에러 발생 -> 특정 객체에 유일한 소유권을 부여하여 해결
  ```
  #include <iostream>
  using namespace std;

 int main()
 {
	 //Unique Pointer 초기화와 함께 int형 값 10으로 동적할당
	 unique_ptr<int> ptr1(new int(10));
	
 	//auto 키워드로 ptr2는 ptr1의 타입을 추론해 받게된다.
	 //move 키워드는 ptr1에서 ptr2로 메모리의 소유권을 이전하기 위해 사용된다.
	 auto ptr2 = move(ptr1);

	 //애초에 ptr1이 소멸되어 접근이 불가하다.
	 //대입 연산자를 이용한 복사는 오류를 발생시킨다.
	 unique_ptr<int> ptr3 = ptr1; // ERROR

	 if (ptr1 == nullptr)
	 {
		 cout << "I'm Dead. Call ptr2 instead." << endl;
		 cout << ptr1 << endl;
	 }
	 cout << *ptr2 << endl;

	 //reset 함수로 메모리 영역을 삭제할 수 있다.
	 ptr2.reset();
	 ptr1.reset();
	 return 0;
 }
 ```
 - make_unique() : 파라미터를 통해 지정된 타입의 객체를 생성하고, 생성된 객체를 가리키는 unique_ptr을 반환
 ```
 #include <iostream>
 using namespace std;

 class Sample 
 {
 public:
	 string name = "";
	 Sample() { cout << "생성" << endl; }
	 Sample(string _name) { name = _name; cout << "생성" << endl; }
	 ~Sample() { cout << "소멸" << endl; }
	 void HelloWorld() { cout << name <<" : Hello World!" << endl; }
 };

 int main()
 {
 	//Sample 클래스 생성
 	unique_ptr<Sample> ptr_smpl = make_unique<Sample>("Sample Pointer");
 	ptr_smpl->HelloWorld();
 	return 0;
 }
 ```
 - shared pointer : 하나의 특정 객체를 참조하는 스마트 포인터의 개수를 참조하는 포인터
 ```
 #include <iostream>
 using namespace std;

 int main()
 {
 	 shared_ptr<double> ptr1(new double(123.456));
	 cout << ptr1.use_count() << endl;
	 auto ptr2(ptr1);
	 cout << ptr2.use_count() << endl;
	 auto ptr3(ptr2);
	 cout << ptr3.use_count() << endl;
	 return 0;
 }
 ```
 - make_shared() : 파라미터를 통해 지정된 타입의 객체를 생성하고, 이를 가리키는 shared_ptr을 반환
 ```
 #include <iostream>
 using namespace std;
 
 class Monster { 
 public:
	 Monster() { cout << "생성" << endl; }
	 ~Monster() { cout << "소멸" << endl; }
 };

 int main()
 {
	 shared_ptr<Monster> mst_ptr1 = make_shared<Monster>();
	 cout << mst_ptr1.use_count() << endl;
	 auto mst_ptr2 = mst_ptr1;
	 cout << mst_ptr1.use_count() << endl;
	 mst_ptr2.reset();
	 cout << mst_ptr1.use_count() << endl;
	 return 0;
 }
 ```
 
 ## Github 정리
 - ! [rejected] main -> main (non-fast-forward) 에러나는 경우 : git push origin +main(+를 붙임)
 
 ## SQLite 쿼리문 정리
 1. Insert
  - insert into [테이블명] (컬럼명1, 컬럼명2, ...) values (값1, 값2, ...)
 2. Delete
  - delete from [테이블명] where (조건)
  - delete from [테이블명] : 해당 테이블 내 모든 데이터를 지우는 경우
 
 ## Django ORM 사용법
  - SQL Query를 통해 queryset을 받고싶을 때 : Model.objects.raw(query) 사용
  >> raw query를 넘기면 raw query must include the primary key 에러 발생 시 해결 : 
  ``` 
  with connection.cursor() as cursor:
  	cursor.execute(raw_query)
  	row = cursor.fetchall()
 ```

