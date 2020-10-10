#include <iostream>
char a[27][2];
using namespace std;

void preorder(char node) {
	if (node == '.' || node == '\0')
		return;
	cout << node;
	preorder(a[node - 65][0]);
	preorder(a[node - 65][1]);
}

void inorder(char node) {
	if (node == '.' || node == '\0')
		return;
	inorder(a[node - 65][0]);
	cout << node;
	inorder(a[node - 65][1]);
}

void postorder(char node) {
	if (node == '.' || node == '\0')
		return;
	postorder(a[node - 65][0]);
	postorder(a[node - 65][1]);
	cout << node;
}

int main() {
	int n;
	char node;

    cin >> n

	for (int i = 0; i < n; i++){
        cin >> node; 
		cin >> a[node - 65][0] >> a[node - 65][1];
	}

	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
	cout << endl;
	return 0;
}