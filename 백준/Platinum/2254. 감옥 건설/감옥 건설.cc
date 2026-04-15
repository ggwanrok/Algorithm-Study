#include <algorithm>
#include <iostream>
#include <stack>
#include <set>
#include <vector>
 
using namespace std;
 
struct Point {
    int x, y;
    int p, q;
    
    Point(){}
    Point(int x1, int y1, int p1 = 0, int q1 = 0): x(x1), y(y1), p(p1), q(q1){}
    
    bool operator<(const Point& O) {
        if (1LL * q * O.p != 1LL * p * O.q) return 1LL * q * O.p < 1LL * p * O.q;
        if (y != O.y) return y < O.y;
        return x < O.x;
    }
}; 
 
long long ccw(const Point& A, const Point& B, const Point& C) {
    long long temp = 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (B.y - A.y) * (C.x - A.x);
    if (temp < 0) return -1;
    else if (temp == 0) return 0;
    else return 1;
}
 
vector<Point> points;
int n, res;
Point flagPoint;
 
int main() {
    cin >> n;
    cin >> flagPoint.x >> flagPoint.y;
    res = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points.push_back(Point(x, y));
    }
    
    while(true) {
        
        sort(points.begin(), points.end());
        
        for (int i = 1; i < points.size(); ++i) {
            points[i].p = points[i].x - points[0].x;
            points[i].q = points[i].y - points[0].y;
        }
        
        // 0번 점을 제외한 나머지 점을 반시계방향 정렬 
        sort(++points.begin(), points.end());
        
        // convex hull 을 한번 찾으면 다른 좌표에 대해서도 찾아야 하므로 백업본이 필요함. 
        vector<Point> backup_points = points; 
        stack<int> st, backup;
        st.push(0);
        st.push(1);
        
        int next = 2;
        //points 를 탐색하면서, st에 확정적인 convex hull 요소들을 채움
        while(next < points.size()) {
            while(st.size() >= 2) {
                int first, second;
                second = st.top();
                st.pop();
                first = st.top();
                if (ccw(points[first], points[second], points[next]) > 0) {
                    st.push(second);
                    break;
                }
            }
            st.push(next++);
        }
        
        
        //위에서 구한 convex hull이 flagPoint에 해당되느냐
        backup = st;
        int start = st.top();
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        
        int check = ccw(points[first], points[second], flagPoint);
        bool isIn = true;
        
        while(!st.empty()) {
            // 스택 순회하면서 다음 점으로 넘어가면서 ccw 파악 
            first = second; 
            second = st.top();
            st.pop();
            
            if (check != ccw(points[first], points[second], flagPoint)) {
                isIn = false;
                break;
            }
        }
            
        // 마지막 녀석과의 비교도 해줘야 해줘야 함
        if (check != ccw(points[second], points[start], flagPoint)) 
            isIn = false;
        
        // 해당 convex hull내부에 flagPoint가 존재한다면,
        // 현재 convex hull을 구성하는 녀석들을 제외하고 위 과정을 반복한다.
        if (isIn == true) {
            res++;
            
            
            set<int> idx;
            for (int i = 0; i < points.size(); ++i){
                idx.insert(i);
            }
            
            while(!backup.empty()) {
                idx.erase(backup.top());
                backup.pop();
            } 
            
            points.clear();
            for (auto iter = idx.begin(); iter != idx.end(); ++iter) 
                points.push_back(backup_points[(*iter)]);
            
        } else {
            break;
        }
        
        // points 의 갯수가 3개 미만이면 다각형이 안그려지니 끝난 셈이다.
        if (points.size() < 3) break; 
    }
    
    cout<<res<<'\n';
    
    return 0;
}