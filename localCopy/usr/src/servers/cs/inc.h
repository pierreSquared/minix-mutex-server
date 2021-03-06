#define _POSIX_SOURCE 1 /* tell headers to include POSIX stuff */
#define _MINIX 1        /* tell headers to include MINIX stuff */
#define _SYSTEM 1       /* get OK and negative error codes */

#include <minix/syslib.h>

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_MUTEXES 1030
#define verbose 0

// Struct defs(!). Appropriate here?
typedef struct
{
  int val;
  struct QueueNode *next;
} QueueNode;

typedef struct
{
  QueueNode *root, *head;
} Queue;

// Externs defined in main.c
EXTERN int identifier;
EXTERN endpoint_t who_e;
EXTERN int call_type;

// Externs defined in lock.c

void initLocks();
void cleanLocks();
int hasLock( int callerId, int mutexId );
void lock( int callerId, int mutexId );
int unlock( int callerId, int mutexId, int notifyCaller );
void parseNotifyLocks( int procId );
void parseExitLocks( int procId );
void printLockQueues();

// Externs defined in queue.c

void initQueue( Queue *q );
void clearQueue( Queue *q );
int isEmpty( Queue *q );
void enqueue( Queue *q, int a );
int top( Queue *q );
void pop( Queue *q );
void printQueue( Queue *q );
int removeFromQueue( Queue *q, int a );
int removeFromTwinQueues( Queue *q, Queue *twin, int a, int *container );

// Externs defined in sender.c

void sendResponse( int procNr, int response );

// Externs defined in wait.c

void initWaits();
void cleanWaits();
void wait( int callerId, int mutexId, int condId );
void broadcast( int callerId, int condId );
void parseExitSignalBroadcasts( int procId, int relock );
