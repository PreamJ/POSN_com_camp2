#include<iostream>
#include<queue>
using namespace std;
int INF = 1000000;
using ii = pair<int, int>;
int main(){
  vector<ii> node[10000];
  //สร้าง Adjacency List เก็บกราฟ
  
  vector<int> dis(10000,INF);
  //สร้างช่องเก็บข้อมูลระยะทางที่สั้นที่สุดไปแต่ละโหนด
  
  vector<bool> visited(10000,false);
  //สร้างช่องเก็บข้อมูลเช็คว่าไปโหนดนี้มาแล้วหรือยังเพื่อลดการทำงาน
  
  priority_queue<ii, vector<ii>, greater<ii> > PQ;
  //สร้าง priority queue ไล่จากน้อยไปมากเก็บว่าเราจะไปสำรวจเส้นทางไหนต่อ
  //note : priority queue คือวิธีการเก็บข้อมูลแบบหนึ่งโดยจะเรียงลำดับข้อมูลที่ใส่ลงไป (มากไปน้อย/น้อยไปมาก)
  
/*--ใส่ข้อมูลการเชื่อมต่อของกราฟ--*/
  node[0].push_back({10,2});
  node[0].push_back({2,3});
  node[3].push_back({3,2});
  node[1].push_back({10,4});
/*--------------------------*/
  
  int start = 0; int final = 2; dis[start] = 0;
/* สมมติให้หาเส้นทางที่สุดจากโหนด 0 ไปโหนด 2 */
  
  PQ.push({dis[start], start});
  // เริ่มเดินทางจากโหนดเริ่มต้น
  
  while(!PQ.empty()){
    int d = PQ.top().first;
    int n = PQ.top().second;
    PQ.pop();
    if(visited[n]) continue;
    visited[n] = true;
    //เช็คดูว่าไปโหนดนี้มาแล้วหรือยังถ้าไปมาแล้วก็ข้ามถ้ายังก็ติ๊กเพิ่มว่าไปมาแล้ว
    
    if(n == final) {
      cout << dis[n];
      break;
    } // ถ้าเป็นโหนดเป้าหมายให้พิมพ์ระยะทางแล้วออกจากลูป
    
    for(auto el : node[n]) {
      int u = el.first;
      int v = el.second;
      if(!visited[v] && dis[n] + u < dis[v]){
        dis[v] = dis[n] + u;
        PQ.push({dis[v], v});
      }
      // เพิ่มเส้นทางจากโหนดที่สำรวจอยู่ไปโหนดอื่นเข้า priority queue
    }
  }
}