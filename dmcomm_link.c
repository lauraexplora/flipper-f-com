#include "dmcomm_link.h"

int32_t dmcomm_reader(void* context) {
    FURI_LOG_I(TAG, "dmcomm_reader start");
    App* app = context;

    uint32_t loops = 0;
    while(app->dmcomm_run) {
        furi_delay_ms(100);
        loops += 1;
        if(loops > 10)
        {
          loops = 0;
          FURI_CRITICAL_ENTER();
          FURI_LOG_I(TAG, "dmcomm_reader loop");
          FURI_CRITICAL_EXIT();
        }
    }

    FURI_LOG_I(TAG, "dmcomm_reader end");
    return 0;
}

/*
furi_thread_flags_set(furi_thread_get_id(context->reader_thread), ReaderThreadFlagExit);

static int32_t example_thermo_reader_thread_callback(void* ctx) {
    ExampleThermoContext* context = ctx;

    for(;;) {
        example_thermo_request_temperature(context);

        const uint32_t flags =
            furi_thread_flags_wait(ReaderThreadFlagExit, FuriFlagWaitAny, UPDATE_PERIOD_MS);

        if(flags != (unsigned)FuriFlagErrorTimeout) break;

        example_thermo_read_temperature(context);
    }

    return 0;
}*/

/*

struct LFRFIDRawFile {
    Stream* stream;
    uint32_t max_buffer_size;

    uint8_t* buffer;
    uint32_t buffer_size;
    size_t buffer_counter;
};

Storage* storage = furi_record_open(RECORD_STORAGE);

file->stream = file_stream_alloc(storage);
file->buffer = NULL;

READ  file_stream_open(file->stream, file_path, FSAM_READ, FSOM_OPEN_EXISTING);

read data:
size_t size_read = stream_read(file->stream, (uint8_t*)&buffer, sizeof(buffer));


WRITE file_stream_open(file->stream, file_path, FSAM_READ_WRITE, FSOM_CREATE_ALWAYS);
size_t size_wrote = stream_write(file->stream, (uint8_t*)&buffer, sizeof(buffer));

stream_free(file->stream);

furi_record_close(RECORD_STORAGE);
*/