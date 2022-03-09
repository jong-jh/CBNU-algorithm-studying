#include <string>
#include <vector>
#include<utility>
#include <queue>
#include <algorithm>

using namespace std;

queue< pair<int,int> >q;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    
    for(int i=0;i<priorities.size();i++){   //큐에 우선순위와, 상응하는 location을 push
        q.push(make_pair(priorities[i],i));
    }
    
    sort(priorities.begin(),priorities.end());  //priorities 정렬
    
    while(1){
        pair<int,int> a = make_pair(q.front().first,q.front().second);   //queue 를 pop 해준다.
        q.pop();

        int check = 0;     //우선순위 체크 변수

        for(int i=0;i<priorities.size();i++){   

            if(a.first < priorities[i]){    //pop 한 값이 우선순위가 제일 크지 않다면
                q.push(a);  //queue 의 맨 뒤로 보내주고
                //answer ++;  //출력 순서도 +1 해준다
                check ++;   //출력되지 않았으므로 check ++
                break;
            }

        }
        if(check == 0){
            if(location == a.second){
                return answer;
            }

            else{
                priorities.erase(priorities.end()-1);
                answer ++;
            }
        }
    }

}