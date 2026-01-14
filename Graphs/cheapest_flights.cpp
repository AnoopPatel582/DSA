#include<iostream>
#include<vector>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> dist(n, 1e9);
    dist[src] = 0;

    for (int i = 0; i <= k; i++) {
        vector<int> temp = dist;

        for (auto &flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int cost = flight[2];

            if (dist[u] != 1e9) {
                temp[v] = min(temp[v], dist[u] + cost);
            }
        }
        dist = temp;
    }

    return dist[dst] == 1e9 ? -1 : dist[dst];
}


int main(){
    int n;
    cout<<"Enter number of cities:";
    cin>>n;
    int m;
    cout<<"Enter the number of flights:";
    cin>>m;
    int from,to,price;
    vector<vector<int>>flights;
    for(int i=0;i<m;i++){
        cout<<"Enter the from node:";
        cin>>from;
        cout<<"Enter the to node:";
        cin>>to;
        cout<<"Enter the price of flight:";
        cin>>price;
        flights.push_back({from,to,price});

    }
    int src,dst,k;
    cout<<"Enter the source node:";
    cin>>src;
    cout<<"Enter the destination node:";
    cin>>dst;
    cout<<"Enter the number of stops:";
    cin>>k;
    int cheapest_price=findCheapestPrice(n,flights,src,dst,k);
    cout<<"The cheapest price: "<<cheapest_price;
    return 0;
}