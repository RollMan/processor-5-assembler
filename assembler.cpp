/*
 * 0x00 OP
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
template <typename T> T swap_endian(T u);

int main(int argc, char* argv[]){
  string op;
  vector<u_int16_t> res;
  map<int, string> idx_label;
  map<string, int> label_addr;
  int addr = 0;

  OP op_code = OP();


  // op is OPCODE or ADDRESS LABEL
  while(cin >> op){
    if(op.substr(0, 2) == "//"){
      int c = cin.get();
      while(c != '\n' && c != EOF);
    }
    // ADDRESS LABEL
    if( op[ op.size() - 1 ] == ':' ){
      string label = op.substr(0, op.size()-1);
      if(label_addr.find(label) != label_addr.end()){
        error("Duplicated label name");
      }
      label_addr[ label ] = addr;
      continue;
    }

    // OPCODE
    string arg;
    cin >> arg;
    if(op == "RET"){
      res.push_back(op_code.v[op]);
      res.push_back((u_int16_t)0);
    }else{
      if(arg[0] == '#'){
        res.push_back(op_code.v[op]);
        arg = arg.substr(1, arg.size()-1);
      }else{
        res.push_back(op_code.v[op+"I"]);
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

  ofstream ofs("dump.hex");
  for(int i = 0; i < res.size(); i++){
    if(i != 0) cout << " ";
    cout << hex << res[i];
    u_int16_t littleendian = swap_endian<u_int16_t>(res[i]);
    ofs.write(reinterpret_cast<char *>(&littleendian), 2);
  }
  ofs.close();
  cout << endl;
  return 0;
}


void error(string reason){
  cout << reason << endl;
  exit(2);
}
template <typename T>
T swap_endian(T u)
{
    static_assert (CHAR_BIT == 8, "CHAR_BIT != 8");

    union
    {
        T u;
        unsigned char u8[sizeof(T)];
    } source, dest;

    source.u = u;

    for (size_t k = 0; k < sizeof(T); k++)
        dest.u8[k] = source.u8[sizeof(T) - k - 1];

    return dest.u;
}
