// a MMStack (Min/Max Stack)
// is a Stack ADT for storing integers
// that can return the Min/Max items in the stack
// all operations (except destroy) are O(1)

struct mmstack;

typedef struct mmstack *MMStack;

// create_MMStack() creates a new empty stack
//   PRE:  true
//   POST: client must eventually call destroy_MMStack
//   TIME: O(1)
MMStack create_MMStack(void);

// destroy_MMStack(mms) empties the stack and frees all memory
//   PRE:  mms is a valid MMStack
//   POST: all memory for mms is freed, and mms is no longer valid
//   TIME: O(n), where n = mms_length(mms)
void destroy_MMStack(MMStack mms);

// mms_length(mms) returns the number of entries in mms
//   PRE:  mms is a valid MMStack
//   POST: returns int >= 0
//   TIME: O(1)
int mms_length(MMStack mms);

// mms_push(mms, i) puts i on the top of the mms
//   PRE:  mms is a valid MMStack
//   POST: length of mms is updated
//   TIME: O(1)
void mms_push(MMStack mms, int i);

// mms_pop(mms) removes and returns item from the top of the mms
//   PRE:  mms is a valid MMStack
//         mms_length(mms) > 0
//   POST: length of mms is updated
//   TIME: O(1)
int mms_pop(MMStack mms);

// mms_min(mms) returns the minimum item stored in the mms
//   PRE:  mms is a valid MMStack
//         mms_length(mms) > 0
//   POST: returns min int stored in mms
//   TIME: O(1)
int mms_min(MMStack mms);

// mms_max(mms) returns the maximum item stored in the mms
//   PRE:  mms is a valid MMStack
//         mms_length(mms) > 0
//   POST: returns max int stored in mms
//   TIME: O(1)
int mms_max(MMStack mms);
