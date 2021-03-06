#ifndef SINGLE_MODE_H
#define SINGLE_MODE_H

#include "replay.h"
#include "mysignal.h"

namespace ygo {

class SingleMode {
private:
	static void* pduel;
	static bool is_closing;
	static bool is_continuing;

public:
	static bool StartPlay();
	static void StopPlay(bool is_exiting = false);
	static void SetResponse(unsigned char* resp, unsigned int len);
	static int SinglePlayThread();
	static bool SinglePlayAnalyze(char* msg, unsigned int len);
	
	static void SinglePlayRefresh(int player, int location, int flag = 0xf81fff);
	static void SinglePlayRefresh(int flag = 0xf81fff);
	static void SinglePlayRefreshSingle(int player, int location, int sequence, int flag = 0xf81fff);
	static void SinglePlayReload();
	static Signal singleSignal;

protected:
	static Replay last_replay;
	static Replay new_replay;
	static ReplayStream replay_stream;
};

}

#endif //SINGLE_MODE_H
