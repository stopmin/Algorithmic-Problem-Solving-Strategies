# 📖 알고리즘 뽀개기
> 가치있는 해결 과정을 공유하고, 함께 성장한다.

- 종만북(알고리즘 해결 전략 1권, 2권)을 각자 학습하며 자신의 속도에 맞추어 필요시 본인 블로그에 정리✏
- 알고리즘 문제를 해결
- 주 1회 스터디 시간에 **페어 프로그래밍**
- [issue](https://github.com/stopmin/Algorithmic-Problem-Solving-Strategies/issues): 문제 추천 및 함께 풀어보고싶은 문제 게시
- [discussion](https://github.com/stopmin/Algorithmic-Problem-Solving-Strategies/discussions): 적극적으로 정리(블로그 링크) 및 함께 나눌 이야기 남기기

### 👀 규칙
**문제풀이에 대한 규칙**
1. 언어에 대한 규칙은 없다. 하지만, 페어프로그래밍 할 때는 `C++`을 써야한다.
2. 가급적 양도 중요하지만, 우아하게 코드를 작성하려고 노력한다.
3. 주에 **최소 3문제** 해결한다.
4. 꼭 종만북과 관련된 문제가 아니더라도 괜찮다.
5. [이슈](https://github.com/stopmin/Algorithmic-Problem-Solving-Strategies/issues)를 적극적으로 활용해서 서로 생각을 동기화시키며 가치있는 해결과정을 공유한다.

**스터디 규칙**
1. 페어 프로그래밍 시간에는 하나의 컴퓨터로 두 명이 번갈아가며 코드를 짠다.
2. 그 주차에 개인이 풀었던 문제에서 더 어려운 된 문제를 페어프로그래밍 문제로 선정한다.
3. 또는 `😁 함께 풀어볼 문제`에서 선정한다.
4. 그 주에 내가 학습했던 것과 풀었던 문제에 대한 TMI를 나눈다.


## 🧑‍💻 참여자 목록
<table>
  <tr>
    <td align="center" width="200px">
      <a href="https://github.com/stopmin" target="_blank">
        <img src="https://avatars.githubusercontent.com/u/108014449?v=4" alt="지민 프로필" />
      </a>
    </td>
    <td align="center" width="200px">
      <a href="https://github.com/pykido" target="_blank">
        <img src="https://avatars.githubusercontent.com/u/77539625?v=4" alt="태윤 프로필" />
      </a>
    </td>
  </tr>
  <tr>
    <td align="center">
      <a href="https://github.com/stopmin" target="_blank">
        지민
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/pykido" target="_blank">
        태윤
      </a>
    </td>
  </tr>
<tr>
    <td align="center">
      <a href="https://stopmin.tistory.com" target="_blank">
        지민 개발 블로그
      </a>
    </td>
    <td align="center">
      <a href="https://animoto1.tistory.com" target="_blank">
        태윤 개발 블로그
      </a>
    </td>
  </tr>
</table>

## ✔️ 커밋 컨벤션
```
{태그}: {플랫폼_문제번호_문제제목)} {커밋 메시지}
```
- 플랫폼에 따라 없는 내용은 생략 가능
- 💡 예시: ✨feat: PGS_다트_게임 알고리즘 구현


### 플랫폼
| 플랫폼    | 태그  |
|--------|-----|
| 백준     | BOJ |
| 프로그래머스 | PGS |
| 리트코드   | LTC |
| 알고스팟   | AGS |

### 이모지 & 태그
- 이모지는 선택에 따라 활용한다.

| 이모지 | 태그      | 설명                      |
|------|---------|-------------------------|
| ✨   | feat    | 새로운 코드 추가               |
| 🐛   | fix     | 문제점 수정                  |
| ♻️    | refactor | 코드 리팩토링                 |
| ✏️   | comment | 주석 추가(코드 변경 X) 혹은 오타 수정 |
| 📝   | docs    | README와 같은 문서 수정        |
| 🔀   | merge   | merge                   |
| 🚚   | rename  | 파일, 폴더명 수정 혹은 이동        |


## ✔️ PR 컨벤션
```
{플랫폼 or 문제번호}_{문제 제목}
```
- `local`에서 `merge`하는 것 대신 `PR`을 통해서만 `main` 브랜치에 머지하도록 한다.
- 💡 예시: PGS 다트 게임 - 그리디

## 📁 디렉터리 구조 예시
```
📦 YourName
├── README.md
├── 📁 Programmers
│    ├── 📁 Level2
│    └── 📁 Level3
└── 📁 Baekjoon
├── 📁 Brute Force
├── 📁 Implementation
├── 📁 Graph Traversal
├── 📁 Greedy
├── 📁 Data Structure
├── 📁 String
├── 📁 Shortest Path
├── 📁 Two Pointer
├── 📁 Divide and conquer
├── 📁 Backtracking
└── 📁 Binary Search
```
- 파일 명은 최소한 서로가 알아볼 수 있을 정도면 된다.
- 디렉터리 구조도 예시일 뿐 서로가 파악할 수 있을 정도면 된다.
