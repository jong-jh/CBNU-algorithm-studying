#include <string>
#include <vector>
#include <queue>    //queue를 쓰기위해 추가
#include <utility>  //pair를 위한 라이브러리

using namespace std;

int solution(vector<int> priorities, int location) {
    queue< pair<int, int> > q;
    priority_queue<int> pq;

    int answer = 0;

    for (vector<int>::size_type i = 0; i < priorities.size(); i++) {
        q.push(pair<int, int>(i, priorities[i]));
    }

    for (vector<int>::size_type i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
    }

    while (!q.empty()) {
        int temp1 = q.front().first;    //위치
        int temp2 = q.front().second;   //우선순위(값)
        q.pop();

        if (temp2 == pq.top()) {
            pq.pop();
            answer++;
            if (temp1 == location)
                break;
        }

        else {
            q.push(pair<int, int>(temp1, temp2));
        }

    }
    return answer;
}


// 처음 실패한 코드
// 실패한 이유 1(0) 1(1) 9(2) 1(3) 1(4) 의 경우 우선순위가 9(2) 1(4) 1(3) 1(1) 1(0)이 됨(첫값이 같으면 두번째인덱스가 큰 게 우선순위가됨)
// 그래서 예외케이스가 생겼다
// 원래 우선순위 큐 하나만 사용해서 풀려고했다. PoP하고 확인해서 맞나. 다르나로 나눠서 할려했음

// #include <string>
// #include <vector>
// #include <queue>
// #include <utility>  //pair를 위한 라이브러리

// using namespace std;

// int solution(vector<int> priorities, int location) {
//     priority_queue< pair<int, int> > pqueue;
//     int answer = 0;

//     for (vector<int>::size_type i = 0; i < priorities.size(); i++) {
//         pqueue.push(make_pair(priorities[i], i));
//     }

//     while (!pqueue.empty()) {
//         int temp = pqueue.top().second;

//         if (temp == location) {
//             answer++;
//             return answer;
//         }

//         else if (temp != location) {
//             answer = answer + 1;
//             pqueue.pop();
//         }
//     }
//     return answer;
// }

