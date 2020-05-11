#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "nodeVertex.h"


using namespace std;

/* 
	@Algorithm Original By : Intan Yuniar Purbasari, S.Kom.,M.Sc.
	@Source Code Original By : Mohammad Faisal Riftiarrasyid (18081010001)
*/

class Graph{
	private:
		nodeVertex *root;
		vector<nodeVertex*> vertexPtrArr;
		vector<int> vertexArr;
	
	public:
		/*             constructor                */
		Graph(){
			root->setName(0);
			vertexPtrArr.push_back(root);
			vertexArr.push_back(0);
		}
		
		/*            Basic Function              */
		bool isEmpty(){
			if(vertexArr.size()==1){
				return true;
			}
			else return false;
		}
		bool isValid(){
			if(vertexArr.size()>=3){
				return true;
			}
			else return false;
		}
		vector<int>::iterator cariIndex(int key){
			vector<int> vkey;
			vkey.push_back(key);
			vector<int>::iterator it=std::search(vertexArr.begin(), vertexArr.end(), vkey.begin(), vkey.end());
			return it;
		}
		
		/*           Mandatory function              */
		void addVertex(int key){
			//make temporary object
			nodeVertex *tempVert = new nodeVertex(key);
			if(isEmpty()){
				//exchange default root
				root=tempVert;
				/*
				root -> setConnectedVertex(tempVert);
				cout << "test";
				tempVert -> setConnectedVertex(root);
				cout << "test";
				root=tempVert;
				*/
				cout << "Adding root : " << key << endl;
			}else {
				cout << "Adding Vertex : " << key << endl;
			}
			//push temp to Vertex Array
			vertexArr.push_back(key);
			vertexPtrArr.push_back(tempVert);
		}
		
		void addEdge(int fromVert, int toVert){
			//make temporary object
			nodeEdge *tempEdge = new nodeEdge();
			//search and save index vertex
			int indexFrom = std::distance(vertexArr.begin(), cariIndex(fromVert));
			int indexTo = std::distance(vertexArr.begin(), cariIndex(toVert));
			//connecting between vertexes
			vertexPtrArr[indexFrom]->setConnectedEdge(tempEdge);
			vertexPtrArr[indexFrom]->setConnectedVertex(vertexPtrArr[indexTo]);
			vertexPtrArr[indexTo]->setConnectedEdge(tempEdge);
			vertexPtrArr[indexTo]->setConnectedVertex(vertexPtrArr[indexFrom]);
			
			//cout << vertexPtrArr[indexFrom] << endl;
		}
		void addEdge(int fromVert, int toVert, int weight){
			//make temporary object
			nodeEdge *tempEdge = new nodeEdge(weight);
			//search and save index vertex
			int indexFrom = std::distance(vertexArr.begin(), cariIndex(fromVert));
			int indexTo = std::distance(vertexArr.begin(), cariIndex(toVert));
			//connecting between vertexes
			vertexPtrArr[indexFrom]->setConnectedEdge(tempEdge);
			vertexPtrArr[indexFrom]->setConnectedVertex(vertexPtrArr[indexTo]);
			vertexPtrArr[indexTo]->setConnectedEdge(tempEdge);
			vertexPtrArr[indexTo]->setConnectedVertex(vertexPtrArr[indexFrom]);
			
			//cout << vertexPtrArr[indexFrom] << endl;
		}
		void getVertex(int vertKey){
			if(cariIndex(vertKey) <= vertexArr.end()){
				cout << "vertex yang anda cari adalah : " << vertKey << " Status : Tidak Ditemukan" << endl;	
			} else {
				cout << "vertex yang anda cari adalah : " << vertKey << " Status : Ditemukan" << endl;
			}
		}
		
		getVertices(){
			vector<int>::iterator it;
			for (it = vertexArr.begin(); it != vertexArr.end(); it++) { 
           		cout << *it << ' '; 
        	} 
		}
		
		
		
		void test(int t){
			int indexTest = std::distance(vertexArr.begin(), cariIndex(t));
			nodeVertex *tempVert = new nodeVertex(t);
			cout << "Node : " << t << " Index : " << NULL << " Ptr : "<< tempVert << endl;
			cout << "Node : " << t << " Index : " << indexTest << " Ptr : "<< vertexPtrArr[indexTest] << endl;
		}
		void printEdge(){
			
		}
};



int main(int argc, char** argv) {
	Graph myGraph;
	myGraph.addVertex(1);
	myGraph.addVertex(2);
	myGraph.test(1);
	myGraph.test(2);
	myGraph.addEdge(1,2);
	myGraph.getVertex(4);
	
	
	return 0;
}
