#include <vector>
#include <iostream>
using namespace std;
class PriorityQueue
{
    vector<int> pq;
public :

    int getsize()
    {
        return pq.size();
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getMin()
    {
        if(isEmpty())
        {
            return 0;
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() -1;
        while(childIndex>0)
        {
            int parentIndex = (childIndex - 1)/2;
            if(pq[childIndex]<pq[parentIndex])
            {
                int temp=pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex]=temp;
            }
            else{
                break;
            }
            childIndex=parentIndex;
        }
    }

    int removeMin()
    {
        int ans = pq[0];
        int n = pq.size() - 1;
        pq[0] = pq[n];
        pq.pop_back();
        //down heapify
        int parentIndex = 0;
        int minIndex=0;
        int Lchild = 2*parentIndex + 1;
        int Rchild = 2*parentIndex + 2;
        while(Lchild<pq.size())
        {
           if(pq[Lchild]<pq[minIndex])
           {
               minIndex = Lchild;
           }
           if(Rchild<pq.size() && pq[Rchild] < pq[minIndex])
            minIndex = Rchild;
           if(minIndex == parentIndex)
            break;

           int temp=pq[minIndex];
           pq[minIndex]=pq[parentIndex];
           pq[parentIndex]=temp;
           minIndex=parentIndex;
           Lchild = 2*parentIndex + 1;
           Rchild = 2*parentIndex + 2;
        }
        return ans;
    }
};

int main() {
    PriorityQueue pq;

    //int choice;
    //cin >> choice;

    //while (choice != -1) {
        //switch (choice) {
            //case 1:  // insert
                //int element;
                //cin >> element;
                pq.insert(10);
                pq.insert(20);
                pq.insert(1);
                pq.insert(11);
              //  break;
            //case 2:  // getMin
                cout << pq.getMin() << "\n";
              //  break;
            //case 3:  // removeMax
                cout << pq.removeMin() << "\n";
              //  break;
            //case 4:  // size
                cout << pq.getsize() << "\n";
          //      break;
        //    case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");

}
