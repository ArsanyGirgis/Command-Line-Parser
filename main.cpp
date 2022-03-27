//============================================================================
// Name        : A1.cpp
// Author      : Arsany
// Version     :
//============================================================================

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
using namespace std;


int main(int argc, char* argv[]){
		int i;
		if (argc > 1){
			if (strcmp(argv[1],"print") == 0){
				if (argc > 2){
					for(i=2; i < argc; i++){
						cout<< argv[i] << " ";
					}
					cout<< endl;
				}
				else{
					cout << "Incorrect Number of Arguments"<<endl;
				}
			}

			else if (strcmp(argv[1],"reverse") == 0){
				if (argc > 2){
					for(i=argc-1; i > 1; i--){
						cout<< argv[i] << " ";
					}
					cout<< endl;
				}
				else{
					cout << "Incorrect Number of Arguments"<<endl;
				}

			}

			else if (strcmp(argv[1],"middle") == 0){
				if (argc > 2){
					if (argc%2 == 0 ){//for even inputs
						cout<< argv[((argc-2)/2)+1] <<" " << argv[((argc-2)/2)+2];
					}
					else{//for odd inputs
						cout<< argv[((argc-1)/2)+1];
					}
					cout<<endl;
				}
				else{
					cout << "Incorrect Number of Arguments"<<endl;
				}

			}

			else if(strcmp(argv[1],"add") == 0){
			    int sum = 0;
			    if (argc > 2){
			    	for(i=2; i < argc; i++){
			    		for (int j = 0; j < strlen(argv[i]); j++){//iterating though each character in each entery
			    			char letter = argv[i][j];
			    			if (isalpha(letter)){
			    				cout << "Incorrect Data Type" << endl;
			    				return 0;//break out of the 2 loops
			    			}
			    		}
			    		sum+=atoi(argv[i]);
			    	}
			    	cout<<sum<<" "<<endl;
			    }

			    else{
			    	cout << "Incorrect Number of Arguments"<<endl;
			    }
			}


            else if(strcmp(argv[1], "upper") == 0){
            	if (argc > 2){
                    for(i=2; i < argc; i++){
                        for (int j = 0; j < strlen(argv[i]); j++){
                        	if ( ((argv[i][j]) >= 'a') && ((argv[i][j]) <= 'z') ){
                        		argv[i][j]=argv[i][j]-32;//asigning ascii code for capital letters
                        	}
                        }
                        cout<<argv[i]<<" ";
                    }
                    cout<<endl;
            	}
			    else{
			    	cout << "Incorrect Number of Arguments"<<endl;
			    }
			}

            else if (strcmp(argv[1],"shuffle") == 0){
            	if (argc > 2){
                	for(i=2; i < argc; i++){
                		for (int j = 0; j < strlen(argv[i]); j+=2){
                			if (argv[i][j+1]!=NULL){
                				char temp = argv[i][j];//to avoid losing it's value
                				argv[i][j]=argv[i][j+1];
                				argv[i][j+1] = temp;
                			}
                		}
                		cout<<argv[i]<<" ";
                	}
                	cout<<endl;
            	}
			    else{
			    	cout << "Incorrect Number of Arguments"<<endl;
			    }
			}

            else if (strcmp(argv[1],"shuffleStatement") == 0){
            	if(argc > 2){
                	for(i=2; i < argc; i+=2){
                		if (argv[i+1]!=NULL){
                			char* temp = argv[i];
                			argv[i]= argv[i+1];
                			argv[i+1]=temp;
                        }
                		cout<<argv[i]<<" "<< argv[i+1]<<" ";
                    }
                	cout<<endl;
            	}
			    else{
			    	cout << "Incorrect Number of Arguments"<<endl;
			    }
            }

            else if(strcmp(argv[1],"random") == 0){
            	if(argc == 6){//format
                	for(i=2; i<argc ; i++){
                		for (int j = 0; j < strlen(argv[i]); j++){//iterating though each character in each entery
                			char letter = argv[i][j];
                			if (isalpha(letter)){
                				cout << "Incorrect Data Type" << endl;
                				return 0;
                			}
                		}
                	}

                	srand(atoi(argv[5]));//seeds from the last element
                	for(int k=0; k < atoi(argv[2]); k++){
                		int randomNumber = rand() % (atoi(argv[4]) - atoi(argv[3]) +1) +  atoi(argv[3]);
                		cout<<randomNumber<<" ";
                	}
                	cout<<" "<<endl;
            	}
			    else{
			    	cout << "Incorrect Number of Arguments"<<endl;
			    }
            }

            else if(strcmp(argv[1],"delete") == 0){
            	if(argc > 2 ){
                	for (int k=0; k < strlen(argv[2]); k++){
    					if(isalpha(argv[2][k])){
    						cout << "Incorrect Data Type" << endl;
    						break;
    					}
                	}

                	int entery = atoi(argv[2]);
                	int range = argc-2;
                	if(entery < range){//the wanted element to be deleted is actually present
                		int position = 3 + entery-1;
                		for(int j=position; j< argc; j++){
                			argv[j]=argv[j+1];
                		}
                		for(i=3; i< argc; i++){
                		    cout<<argv[i]<<" ";
                		}
                		cout<<" "<<endl;
                	}
                	else{
                		cout << "Incorrect Number of Arguments"<<endl;
                	}
            	}
			    else{
			    	cout << "Incorrect Number of Arguments"<<endl;
			    }
            }

			else{
                    cout<<"Undefined Command"<<endl;
			}
		}
		else{
			cout << "Undefined Command"<<endl;
		}
	return 0;
}
