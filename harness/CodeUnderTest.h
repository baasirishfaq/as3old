// Copyright 2025 daman
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef CODE_UNDER_TEST_H
#define CODE_UNDER_TEST_H

#include "../include/givenA3.h"
#include "../src/createPlayList.c"
#include "../src/addNewSong.c"
#include "../src/playSongGivenId.c"
#include "../src/playSongGivenName.c"
#include "../src/countNotesInASong.c"

// Function declarations (if not already in givenA3.h)
// int createPlayList(A3Song **headLL, const char *fileName);
// bool addNewSong(A3Song **headLL, int beginOrEnd);

#endif // CODE_UNDER_TEST_H