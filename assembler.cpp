/*
 * 0x00 opcode
 * 0x10 ARG
 * 0x20 OP
 * 0x30 ARG
 */

/*
 * Allocate memory space for RET argument
 */

#include "const.h"
#include <climits>

#include <bits/stdc++.h>
using namespace std;

void error(string reason);

int main(int argc, char* argv[]){

  if(argc != 2){
    error("Usage: assembler FILENAME");
  }

  vector<u_int16_t> res;
  map<int, string> idx_label;
  map<string, int> label_addr;
  int addr = 0;
  bool prev_also_label = false;

  OP opname2opcode = OP();


  string filename = string(argv[1]);
  ifstream ifs;
  ifs.open(filename);

  // opecode is OPCODE or ADDRESS LABEL
  string opname;
  while(ifs >> opname){
    // ignore COMMENT
    if(opname.substr(0, 2) == "//"){
      int c = ifs.get();
      while(c != '\n' && c != EOF) c = ifs.get();
      continue;
    }

    // ADDRESS LABEL
    if( opname[ opname.size() - 1 ] == ':' ){
      string label = opname.substr(0, opname.size()-1);
      if(label_addr.find(label) != label_addr.end()){
        error("Duplicated label name");
      }
      if(prev_also_label == true){
        addr++;
      }
      label_addr[ label ] = addr;
      continue;
    }
    prev_also_label = false;

    // OPCODE
    if(opname2opcode.v.find(opname) == opname2opcode.v.end()){
      error("No such operator: " + opname);
    }
    if(opname == "RET" || opname == "HALT" || opname == "LAA"){
      // RET has no argument
      res.push_back(opname2opcode.v[opname]);
      res.push_back((u_int16_t)0);
    }else{
      string arg;
      ifs >> arg;
      if(arg[0] == '#'){
        res.push_back(opname2opcode.v[opname]);
        arg = arg.substr(1, arg.size()-1);
        cout << opname << " #" << arg << endl;
      }else{
        res.push_back(opname2opcode.v[opname+"I"]);
      }
      if( isdigit(arg[0]) ){
        res.push_back( atoi(arg.c_str()) );
      }else{ // label name has come
        res.push_back(-1);
        idx_label.insert( pair<int, string>(res.size()-1, arg) );
      }
    }

    addr++;
  }

  for(map<int, string>::iterator it = idx_label.begin(); it != idx_label.end(); it++){
    int idx = it->first;
    string label = it->second;
    res[idx] = label_addr[label];
  }

  int path_i = filename.find_last_of("/");
  int ext_i = filename.find_last_of(".");
  if(path_i == string::npos){
    path_i = 0;
  }
  if(ext_i == string::npos){
    cerr << "filename error" << endl;
    exit(1);
  }
  ofstream ofs(filename.substr(path_i,ext_i-path_i) + ".hex");
  int i = 0;
  while(i < res.size()){
    ofs << "0x" << setfill('0') << setw(4) << hex << res[i] << endl;;
    i++;
  }
  ifs.close();
  ofs.close();
  return 0;
}


void error(string reason){
  cout << reason << endl;
  exit(2);
}
