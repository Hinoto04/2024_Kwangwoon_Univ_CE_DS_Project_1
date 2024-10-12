#include "Manager.h"

int timeInSeconds(int h, int m, int s) { //time to seconds
    return h*3600 + m*60 + s;
}

Manager::Manager()
{

}
Manager::~Manager()
{

}

void Manager::Run(const char* command)
{
    // Open command & log file
    fcmd.open(command);
    flog.open("log.txt");
    if (!fcmd)
    {
        flog << "Fail to open command file" << endl;
        exit(-1);
    }

    // Read and Run command


    fcmd.close();
    flog.close();
    return;
}

void Manager::PrintSuccess(const char* cmd)
{
    flog << "===== " << cmd << " =====" << endl;
    flog << "Success" << endl;
    flog << "===============\n" << endl;
}
void Manager::PrintErrorCode(int num)
{
    flog << "===== ERROR =====" << endl;
    flog << num << endl;
    flog << "===============\n" << endl;
}

// LOAD
void Manager::load() {
    ifstream fsub; //subtitle file stream
    fsub.open("subtitle.txt");

    if(!fsub) { //file not found
        PrintErrorCode(100);
    }
    if(!(this->q->isEmpty())) { //already loaded
        PrintErrorCode(100);
    }
    
    string str;
    while(getline(fsub, str)) {
        int h = stoi(str.substr(0, 2)); //00:
        int m = stoi(str.substr(3, 2)); //00:|00:
        int s = stoi(str.substr(6, 2)); //00:00:|00
        //int time = timeInSeconds(h, m, s);
        string content = str.substr(9) //00:00:00 |

        this.q.push(h, m, s, content)
    }

    return;
}
// QPOP
void Manager::qpop();
// PRINT
void Manager::print();
void Manager::print(int number);
// SECTION
void Manager::section(int number, int start, int end);
// DELETE
void del(int mode, int time);
