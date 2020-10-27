#include <stdio.h>
#include <unistd.h>
#include <map>
#include <string>
#include <getopt.h>

using namespace std;

string VERSION = "228";

int main(int argc, char *argv[]){
    int res=0;
	map <string, bool> used;

	int option_index = -1;
	const char* short_options = "hlvfeV::?";
	
	const struct option long_options[] = {
        {"help",0,NULL,'h'},
        {"list",0,NULL,'l'},
        {"version",0,NULL,'v'},
        {"fox",0,NULL,'f'},
        {"elephant",0,NULL,'e'},
        {"value",2,NULL,'V'},
        {NULL,0,NULL,0},
    };

    while ((res = getopt_long(argc,argv,short_options,long_options, &option_index)) != -1){
		switch (res){
		case 'h': {
			if (used["h"] == false) {
				printf("Arg: Help\n");
				used["h"] = true;
				break;
			}
			break;
		}
		case 'l': {
			if (used["l"] == false) {
				printf("Arg: List\n");
				used["l"] = true;
				break;
			}
			break;
		}
		case 'v': {
			if (used["v"] == false) {
				printf("version: %c\n", VERSION); 
				used["v"] = true;
				break;
			}
			break;
		}
		case 'V': {
			if (used["V"] == false) {
				if (optarg == NULL) {
					printf("Arg: value\n"); 
					used["V"] = true;
				} else {
                    if (*optarg == '0') {
                        printf("0\n");
                    }
                    else if (*optarg == '1') {
                        printf("1\n");
                    }
                    else {
                        printf("Arg: %s value\n", optarg); 
                    }
					used["V"] = true;
				}
				break;
			}
			break;
		}
        case 'f': {
            if (used["f"] == false) {
				printf("Fox\n"); 
				used["f"] = true;
				break;
			}
			break;
        }
        case 'e': {
            if (used["e"] == false) {
				printf("Elephant\n"); 
				used["e"] = true;
				break;
			}
			break;
        }
		case '?': default: {
			printf("Key %c is not found\n", res);
			break;
			}
        };
		option_index = -1;
	};
}
