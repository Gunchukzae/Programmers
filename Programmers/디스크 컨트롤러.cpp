#include <string>
#include <vector>
#include <queue>

using namespace std;

namespace 디스크컨트롤러 {
    int solution(vector<vector<int>> jobs)
    {
        int answer = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        //jobs[시작시간, 작업시간] -> 시작시간이 짧은 순으로 정렬
        sort(jobs.begin(), jobs.end());

        int nSumTime = 0;   //전체 소요시간
        int nTime = 0;      //현재 시간
        int nIndex = 0;     //다음 작업의 인덱스

        while (nIndex < jobs.size() || !minHeap.empty())
        {
            //현재 시간에 시작할 수 있는 작업을 우선순위 큐에 추가
            while (nIndex < jobs.size() && jobs[nIndex][0] <= nTime)
            {
                int nTakingTime = jobs[nIndex][1]; //작업 소요시간
                minHeap.push({ nTakingTime, jobs[nIndex][0] }); //minHeap[작업시간, 시작시간] -> 작업시간이 짧은 순으로 정렬
                nIndex++;
            }

            if (!minHeap.empty())
            {
                //가장 짧은 소요 시간을 가진 job
                auto currentJob = minHeap.top();
                minHeap.pop();

                nTime += currentJob.first;              //현재시간 += 작업시간
                nSumTime += nTime - currentJob.second;  //전체 소요시간 += 현재시간 - 시작시간
            }
            else
            {
                nTime++;
            }
        }

        answer = nSumTime / jobs.size();

        return answer;
    }
}