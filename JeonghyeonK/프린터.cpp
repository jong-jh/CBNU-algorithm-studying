#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int now_index = 0;  // 탐색하고 있는 문서의 인덱스

    while (1) {
        int max_prior = 0; // priorities에서 최대값을 찾아 값을 저장
        int max_index = 0; // 찾은 최대값의 인덱스를 저장

        for (int i = 0; i < (int)priorities.size(); i++) {

            // 값이 기존 최대값보다 크면 최대값 변경
            if (max_prior < priorities[now_index]) {
                max_prior = priorities[now_index];
                max_index = now_index;
            }

            //한 칸씩 이동하면서 최대값을 찾다가 인덱스가 범위 넘어가면 첫번째 인덱스로 이동
            now_index++;
            if (now_index == priorities.size()) now_index = 0;
        }

        //찾은 최대값의 인덱스가 내가 인쇄를 요청한 문서의 인덱스가 아닐 경우
        if (max_index != location) {
            priorities.erase(priorities.begin() + max_index);   // 최대값 원소를 벡터에서 삭제
            if (max_index < location) location--;   // location 위치도 같이 수정

            //기존 최대값 원소의 다음 원소부터 다시 한바퀴 탐색
            if (max_index == priorities.size()) now_index = 0;
            else now_index = max_index;

            answer++; //최대값 찾아 삭제할 때 마다 answer++
        }

        //찾은 최대값의 인덱스가 내가 인쇄를 요청한 문서의 인덱스가 맞다면 while문 탈출
        else break;

    }

    return answer + 1;
}