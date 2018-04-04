#include "follower.h"
#include "buffer_manager.h"
#include <thread>
#include <atomic>
#include "data_writer.h"

using namespace nxtftl;

int main()
{
	buffer_manager<position> buffers{ 10, 100 };
    follower follow{ &buffers, 10, 100, 400ms, 15ms };
    data_writer writer{ &buffers };

    std::thread data_writer_thread([&writer]() {
        writer.run();
    });
	
    follow.Init();
	follow.Run();

    buffers.complete_adding();

    data_writer_thread.join();

    std::getchar();
}
