#include <windows.h>
#include "exedit.hpp"

#define TRACK_N 2
ExEdit::Filter ef, tef;
inline static char name[] = "入力test";
inline static char name2[] = "効果test";
inline static char track_name1[] = "Hz";
inline static char track_name2[] = "vol";
inline static char* track_name[TRACK_N] = { track_name1, track_name2 };
inline static int track_default[TRACK_N] = { 48000, 0 };
inline static int track_s[TRACK_N] = { 6000, 0 };
inline static int track_e[TRACK_N] = { 384000, 100 };
inline static int track_scale[TRACK_N] = { 100, 1 };
inline static int track_drag_min[TRACK_N] = { 12000, 0 };
inline static int track_drag_max[TRACK_N] = { 192000, 80 };


BOOL func_proc(ExEdit::Filter* efp, ExEdit::FilterProcInfo* efpip) {
    /*
    double audio_rate = (double)efpip->audio_rate;
    int milliframe, currentframe;
    if (efpip->audio_speed) {
        milliframe = efpip->audio_milliframe + (efpip->frame - efpip->frame_num) * 1000;
        audio_rate *= 1000000.0 / (double)efpip->audio_speed;
        currentframe = (int)round((double)milliframe * 1000 / (double)efpip->audio_speed);
    } else {
        milliframe = efpip->frame * 1000;
        currentframe = efpip->frame;
    }
    if (efpip->audio_ch == 2) {
        for (int i = 0; i < efpip->audio_n; i++) {
            efpip->audio_data[i * 2] = efpip->audio_data[i * 2 + 1] = f();
        }
    } else {
        for (int i = 0; i < efpip->audio_n; i++) {
            efpip->audio_data[i] = f();
        }
    }
    */
    return TRUE;
}

ExEdit::Filter* filter_list[] = {
    &ef,
    &tef,
    NULL
};

EXTERN_C __declspec(dllexport)ExEdit::Filter** __stdcall GetFilterTableList() {
    ef.flag = ExEdit::Filter::Flag::Input | ExEdit::Filter::Flag::Audio;
    ef.name = name;
    ef.track_n = 1;
    ef.track_name = track_name;
    ef.track_default = track_default;
    ef.track_s = track_s;
    ef.track_e = track_e;
    ef.track_scale = track_scale;
    ef.track_drag_min = track_drag_min;
    ef.track_drag_max= track_drag_max;
    ef.check_n = 0;
    ef.func_proc = func_proc;

    tef.flag = ExEdit::Filter::Flag::Effect | ExEdit::Filter::Flag::Audio;
    tef.name = name2;
    tef.track_n = 2;
    tef.track_name = track_name;
    tef.track_default = track_default;
    tef.track_s = track_s;
    tef.track_e = track_e;
    tef.track_scale = track_scale;
    tef.track_drag_min = track_drag_min;
    tef.track_drag_max = track_drag_max;
    tef.check_n = 0;
    tef.func_proc = func_proc;

    return filter_list;
}
