#ifndef LOCK_H
#define LOCK_H

#include <mutex>
class Lock {
		public:
					explicit Lock(std::mutex& mutex);
					~Lock();
		private:
				std::mutex& mutex;
};

#endif
