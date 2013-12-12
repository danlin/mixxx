var num_decks = 0;
var num_samplers = 0;
var channel_hotcue_count = 32;

function init() {
    console.log("Init Engine JavaScript");
    // Microphone
    MixxxEngine.enableEvent("[Microphone]","enabled");
    MixxxEngine.enableEvent("[Microphone]","orientation");
    MixxxEngine.enableEvent("[Microphone]","PeakIndicator");
    MixxxEngine.enableEvent("[Microphone]","talkover");
    MixxxEngine.enableEvent("[Microphone]","volume");
    MixxxEngine.enableEvent("[Microphone]","VuMeter");    

    // Master
    MixxxEngine.enableEvent("[Master]","balance");
    MixxxEngine.enableEvent("[Master]","crossfader");
    MixxxEngine.enableEvent("[Master]","crossfader_down");
    MixxxEngine.enableEvent("[Master]","crossfader_down_small");
    MixxxEngine.enableEvent("[Master]","crossfader_up");
    MixxxEngine.enableEvent("[Master]","crossfader_up_small");
    MixxxEngine.enableEvent("[Master]","headVolume");
    MixxxEngine.enableEvent("[Master]","headMix");
    MixxxEngine.enableEvent("[Master]","latency");
    MixxxEngine.enableEvent("[Master]","num_decks");
    MixxxEngine.enableEvent("[Master]","num_samplers");
    MixxxEngine.enableEvent("[Master]","PeakIndicator");
    MixxxEngine.enableEvent("[Master]","samplerate");
    MixxxEngine.enableEvent("[Master]","volume");
    MixxxEngine.enableEvent("[Master]","VuMeter");
    MixxxEngine.enableEvent("[Master]","VuMeterL");
    MixxxEngine.enableEvent("[Master]","VuMeterR");
    
    // Playlist
    MixxxEngine.enableEvent("[Playlist]","LoadSelectedIntoFirstStopped");
    MixxxEngine.enableEvent("[Playlist]","SelectNextPlaylist");
    MixxxEngine.enableEvent("[Playlist]","SelectNextTrack");
    MixxxEngine.enableEvent("[Playlist]","SelectPrevPlaylist");
    MixxxEngine.enableEvent("[Playlist]","SelectPrevTrack");
    MixxxEngine.enableEvent("[Playlist]","SelectTrackKnob");
    
    // Decks
    num_decks = MixxxEngine.getValue("[Master]", "num_decks");
    for (var deck = 1; deck <= num_decks; deck++) {
        enableDeckEvents(deck);
    }

    // Sampler
    num_samplers = MixxxEngine.getValue("[Master]", "num_samplers");
    for (var sampler = 1; sampler <= num_samplers; sampler++) {
        enableSamplerEvents(sampler);
    }
    
    // Vinyl Control
    MixxxEngine.enableEvent("VinylControl","Toggle");
}

function enableDeckEvents(deck) {
    MixxxEngine.enableEvent("[Channel" + deck + "]","back");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beat_active");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop");

    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_0.0625_activate");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_0.125_activate");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_0.25_activate");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_0.5_activate");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_1_activate");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_2_activate");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_4_activate");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_8_activate");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_16_activate");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_32_activate");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_64_activate");    

    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_0.0625_toggle");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_0.125_toggle");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_0.25_toggle");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_0.5_toggle");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_1_toggle");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_2_toggle");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_4_toggle");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_8_toggle");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_16_togglee");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_32_toggle");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_64_toggle");
    
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_0.0625_enabled");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_0.125_enabled");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_0.25_enabled");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_0.5_enabled");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_1_enabled");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_2_enabled");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_4_enabled");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_8_enabled");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_16_enablede");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_32_enabled");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatloop_64_enabled");
    
    MixxxEngine.enableEvent("[Channel" + deck + "]","beats_translate_curpos");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatsync");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatsync_phase");
    MixxxEngine.enableEvent("[Channel" + deck + "]","beatsync_tempo");
    MixxxEngine.enableEvent("[Channel" + deck + "]","bpm");
    MixxxEngine.enableEvent("[Channel" + deck + "]","bpm_tap");
    MixxxEngine.enableEvent("[Channel" + deck + "]","cue_default");
    MixxxEngine.enableEvent("[Channel" + deck + "]","cue_point");
    MixxxEngine.enableEvent("[Channel" + deck + "]","cue_preview");
    MixxxEngine.enableEvent("[Channel" + deck + "]","cue_set");
    MixxxEngine.enableEvent("[Channel" + deck + "]","cue_simple");
    MixxxEngine.enableEvent("[Channel" + deck + "]","duration");
    MixxxEngine.enableEvent("[Channel" + deck + "]","eject");
    MixxxEngine.enableEvent("[Channel" + deck + "]","end");
    MixxxEngine.enableEvent("[Channel" + deck + "]","file_bpm");
    MixxxEngine.enableEvent("[Channel" + deck + "]","filterHigh");
    MixxxEngine.enableEvent("[Channel" + deck + "]","filterHighKill");
    MixxxEngine.enableEvent("[Channel" + deck + "]","filterLow");
    MixxxEngine.enableEvent("[Channel" + deck + "]","filterLowKill");
    MixxxEngine.enableEvent("[Channel" + deck + "]","filterMid");
    MixxxEngine.enableEvent("[Channel" + deck + "]","filterMidKill");
    MixxxEngine.enableEvent("[Channel" + deck + "]","fwd");

    for (var cue = 1; cue <= channel_hotcue_count; cue++) {
        MixxxEngine.enableEvent("[Channel" + deck + "]","hotcue_"+cue+"_activate");
        MixxxEngine.enableEvent("[Channel" + deck + "]","hotcue_"+cue+"_clear");
        MixxxEngine.enableEvent("[Channel" + deck + "]","hotcue_"+cue+"_enabled");
        MixxxEngine.enableEvent("[Channel" + deck + "]","hotcue_"+cue+"_goto");
        MixxxEngine.enableEvent("[Channel" + deck + "]","hotcue_"+cue+"_gotoandstop");
        MixxxEngine.enableEvent("[Channel" + deck + "]","hotcue_"+cue+"_position");
        MixxxEngine.enableEvent("[Channel" + deck + "]","hotcue_"+cue+"_set");
    }
    
    MixxxEngine.enableEvent("[Channel" + deck + "]","jog");
    MixxxEngine.enableEvent("[Channel" + deck + "]","keylock");
    MixxxEngine.enableEvent("[Channel" + deck + "]","LoadSelectedTrack");
    MixxxEngine.enableEvent("[Channel" + deck + "]","loop_double");
    MixxxEngine.enableEvent("[Channel" + deck + "]","loop_enabled");
    MixxxEngine.enableEvent("[Channel" + deck + "]","loop_end_position");
    MixxxEngine.enableEvent("[Channel" + deck + "]","loop_halve");
    MixxxEngine.enableEvent("[Channel" + deck + "]","loop_in");
    MixxxEngine.enableEvent("[Channel" + deck + "]","loop_out");
    MixxxEngine.enableEvent("[Channel" + deck + "]","loop_scale");
    MixxxEngine.enableEvent("[Channel" + deck + "]","loop_start_position");
    MixxxEngine.enableEvent("[Channel" + deck + "]","orientation");
    MixxxEngine.enableEvent("[Channel" + deck + "]","PeakIndicator");
    MixxxEngine.enableEvent("[Channel" + deck + "]","pfl");
    MixxxEngine.enableEvent("[Channel" + deck + "]","play");
    MixxxEngine.enableEvent("[Channel" + deck + "]","playposition");
    MixxxEngine.enableEvent("[Channel" + deck + "]","pregain");
    MixxxEngine.enableEvent("[Channel" + deck + "]","quantize");
    MixxxEngine.enableEvent("[Channel" + deck + "]","quantize_beat");
    MixxxEngine.enableEvent("[Channel" + deck + "]","rate");
    MixxxEngine.enableEvent("[Channel" + deck + "]","rate_dir");
    MixxxEngine.enableEvent("[Channel" + deck + "]","rate_perm_down");
    MixxxEngine.enableEvent("[Channel" + deck + "]","rate_perm_down_small");
    MixxxEngine.enableEvent("[Channel" + deck + "]","rate_perm_up");
    MixxxEngine.enableEvent("[Channel" + deck + "]","rate_perm_up_small");
    MixxxEngine.enableEvent("[Channel" + deck + "]","rate_temp_down");
    MixxxEngine.enableEvent("[Channel" + deck + "]","rate_temp_down_small");
    MixxxEngine.enableEvent("[Channel" + deck + "]","rate_temp_up");
    MixxxEngine.enableEvent("[Channel" + deck + "]","rate_temp_up_small");
    MixxxEngine.enableEvent("[Channel" + deck + "]","rateRange");
    MixxxEngine.enableEvent("[Channel" + deck + "]","reloop_exit");
    MixxxEngine.enableEvent("[Channel" + deck + "]","repeat");
    MixxxEngine.enableEvent("[Channel" + deck + "]","reverse");
    MixxxEngine.enableEvent("[Channel" + deck + "]","scratch");
    MixxxEngine.enableEvent("[Channel" + deck + "]","scratch2");
    MixxxEngine.enableEvent("[Channel" + deck + "]","scratch2_enable");
    MixxxEngine.enableEvent("[Channel" + deck + "]","start");
    MixxxEngine.enableEvent("[Channel" + deck + "]","start_play");
    MixxxEngine.enableEvent("[Channel" + deck + "]","track_samplerate");
    MixxxEngine.enableEvent("[Channel" + deck + "]","track_samples");
    MixxxEngine.enableEvent("[Channel" + deck + "]","volume");
    MixxxEngine.enableEvent("[Channel" + deck + "]","vinylcontrol_enabled");
    MixxxEngine.enableEvent("[Channel" + deck + "]","vinylcontrol_cueing");
    MixxxEngine.enableEvent("[Channel" + deck + "]","vinylcontrol_mode");
    MixxxEngine.enableEvent("[Channel" + deck + "]","vinylcontrol_status");
    MixxxEngine.enableEvent("[Channel" + deck + "]","VuMeter");
    MixxxEngine.enableEvent("[Channel" + deck + "]","VuMeterL");
    MixxxEngine.enableEvent("[Channel" + deck + "]","VuMeterR");
    MixxxEngine.enableEvent("[Channel" + deck + "]","wheel");
}

function enableSamplerEvents(sampler) {
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","back");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beat_active");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop");
    
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_0.0625_activate");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_0.125_activate");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_0.25_activate");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_0.5_activate");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_1_activate");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_2_activate");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_4_activate");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_8_activate");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_16_activate");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_32_activate");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_64_activate");    
    
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_0.0625_toggle");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_0.125_toggle");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_0.25_toggle");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_0.5_toggle");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_1_toggle");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_2_toggle");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_4_toggle");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_8_toggle");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_16_togglee");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_32_toggle");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_64_toggle");
    
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_0.0625_enabled");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_0.125_enabled");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_0.25_enabled");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_0.5_enabled");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_1_enabled");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_2_enabled");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_4_enabled");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_8_enabled");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_16_enabled");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_32_enabled");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatloop_64_enabled");
    
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beats_translate_curpos");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatsync");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatsync_phase");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","beatsync_tempo");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","bpm");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","bpm_tap");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","cue_default");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","cue_point");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","cue_preview");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","cue_set");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","cue_simple");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","duration");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","eject");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","end");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","file_bpm");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","filterHigh");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","filterHighKill");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","filterLow");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","filterLowKill");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","filterMid");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","filterMidKill");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","fwd");
    
    for (var cue = 1; cue <= channel_hotcue_count; cue++) {
        MixxxEngine.enableEvent("[Sampler" + sampler + "]","hotcue_"+cue+"_activate");
        MixxxEngine.enableEvent("[Sampler" + sampler + "]","hotcue_"+cue+"_clear");
        MixxxEngine.enableEvent("[Sampler" + sampler + "]","hotcue_"+cue+"_enabled");
        MixxxEngine.enableEvent("[Sampler" + sampler + "]","hotcue_"+cue+"_goto");
        MixxxEngine.enableEvent("[Sampler" + sampler + "]","hotcue_"+cue+"_gotoandstop");
        MixxxEngine.enableEvent("[Sampler" + sampler + "]","hotcue_"+cue+"_position");
        MixxxEngine.enableEvent("[Sampler" + sampler + "]","hotcue_"+cue+"_set");
    }
    
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","jog");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","keylock");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","LoadSelectedTrack");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","loop_double");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","loop_enabled");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","loop_end_position");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","loop_halve");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","loop_in");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","loop_out");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","loop_scale");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","loop_start_position");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","orientation");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","PeakIndicator");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","pfl");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","play");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","playposition");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","pregain");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","quantize");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","quantize_beat");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","rate");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","rate_dir");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","rate_perm_down");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","rate_perm_down_small");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","rate_perm_up");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","rate_perm_up_small");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","rate_temp_down");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","rate_temp_down_small");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","rate_temp_up");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","rate_temp_up_small");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","rateRange");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","reloop_exit");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","repeat");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","reverse");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","scratch");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","scratch2");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","scratch2_enable");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","start");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","start_play");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","track_samplerate");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","track_samples");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","volume");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","vinylcontrol_enabled");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","vinylcontrol_cueing");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","vinylcontrol_mode");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","vinylcontrol_status");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","VuMeter");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","VuMeterL");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","VuMeterR");
    MixxxEngine.enableEvent("[Sampler" + sampler + "]","wheel");
}

function onMixxxEvent(configKey, value) {
    
    switch (configKey) {
        case "num_decks":
            num_decks = value;
            break;
        case "num_samplers":
            num_samplers = value;
            break;
        case "[Channel1],VuMeterL":
        case "[Channel1],VuMeterR":
        case "[Channel1],VuMeter":
        case "[Master],VuMeter":
        case "[Master],VuMeterR":
        case "[Master],VuMeterL":
            break;
        default:
            console.log("Mixxx Event: " + configKey + " = " + value);
            break;
    }
}

function hideMixer() {
    console.log("Hide Mixer");
    mixxxDeckView.showMixer = false;
}

