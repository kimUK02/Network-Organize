# HTTP
## HTTP/ 1.1

(Hypertext Transfer Protocol)

TCP위에서 작동하는 프로토콜로 이미지, 동영상,오디오, 등등을 보낼 수 있다.

![HTTP](./imgs/http.png)
---
### working structure

> client : URI를 이용하여 서버에 접속하고 데이터를 요청할 수 있다 
>>ex)chrome, firefox, IE

> server : client의 요청을 받아서 해석, 응답을 하는 소프트웨어가 설치된 컴퓨터 
>> ex) Apache, nginx, IIS, lighttpd

>표준 포트는 80번
---
### Connectionless

연결하고 Request하고 Response를 한후 접속이 끊긴다 
- 이를 보안하기위해 Ajax와 Web Socket을 사용한다

또한 통신이 끝나면 현재 상태가 저장되지 않는다
- 이를 보한하기 위해 쿠키나 세션이 나왔다.

---

### Request Packet



| Method | Explanation | Body |
|:--------|:--------:|:--------:|
| Get | 서버에서 Data를 가져온다 | X |
| HEAD | 서버에서 Data의 헤더만 가져온다 | X |
| POST | 서버에서 Data에 대해 어떤 처리를 요청  |O|
| PUT |   서버에서 요청 바디를 저장함 | O |
| TRACE | 메세지가 서버에 도달하는 과정을 추적 | X |
| OPTIONS | 서버가 어떤 메서드를 수행할 수 있는지 확인 | X |
| DELETE | 서버에서 데이타를 삭제한다 | X |
---

