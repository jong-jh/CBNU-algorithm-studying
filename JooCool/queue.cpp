#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// 두가지 사항을 고려해야하기떄문에 구조체 생성
struct PrintJob {
    int priority;
    int location;
};
int solution(vector<int> priorities, int location) {

    queue<PrintJob> printer; //큐에 인덱스 삽입

    for (int i = 0; i < priorities.size(); i++)
    {
        PrintJob job;
        job.location = i;
        job.priority = priorities[i];
        printer.push(job);
    }
    int answer = 0;
    while (!printer.empty()) // 0번째값을 꺼내서 최대 우선순위가 아니라면 다시 끝으로 넘김
    {
        PrintJob job = printer.front();
        printer.pop();
        if (job.priority < *max_element(priorities.begin(), priorities.end()))
        {
            printer.push(job);
        }
        else {
            answer++;
            if (job.location == location) //최대 우선순위라면 내가 찾는 job과 일치한지 확인하기.
                break;
            priorities[job.location] = 0;

        }
    }
    return answer;
}

int main(void)
{
    vector<int> properties = { 2,1,3,2 };
    cout << solution(properties, 2);
    return 0;
}