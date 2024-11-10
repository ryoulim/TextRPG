#pragma once

#define SAFE_DELETE(X) if ( X != nullptr ) { delete X ; X = nullptr; }
#define SAFE_DELETE_ARRAY(X) if ( X != nullptr ) { delete[] X ; X = nullptr; }

#define CLEAR system("cls")
#define LINE_UI cout << "=====================================" << endl
#define DELAY(X) _Thrd_sleep_for( X )
#define PAUSE system("pause")

#define PERCENT(X) 0 < (X) - rand()%100