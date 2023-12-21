// Abstraction around cloud storage in case we want to support multiple providers.
#ifndef CLOUD_DRIVE_H
#define CLOUD_DRIVE_H 1

#include <stddef.h>
#include <stdint.h>

typedef struct cloud_drive_t cloud_drive_t;

typedef struct {
    const char* name;
    void* avatar;
    int avatar_width;
    int avatar_height;
} cloud_user_info_t;

// Create an instance of a cloud drive. If there's already a token, use it.
// Otherwise, prompt the user to authenticate and save the token.
// Also fills the file map with the files in the cloud.
void cloud_drive_create(void(*ready_callback)(cloud_drive_t*));

// Destroy the cloud drive instance.
void cloud_drive_destroy(cloud_drive_t* cloud_drive);

// Log out of the cloud drive and forget the token.
void cloud_drive_logout(cloud_drive_t* cloud_drive);

// Upload a file to the cloud.
// Calls cleanup_callback when the upload is complete.
void cloud_drive_upload(cloud_drive_t* cloud_drive, const char* filename, const char* parent, const char* mime_type, void* data, size_t size, void(*cleanup_callback)(void*, void*), void* userdata);

// Download a file from the cloud.
// Calls callback when the download is complete.
void cloud_drive_download(cloud_drive_t* cloud_drive, const char* filename, void(*callback)(void* userdata, void* data, size_t size), void* userdata);

// Has lifetime equal to the cloud drive instance.
cloud_user_info_t cloud_drive_get_user_info(cloud_drive_t* cloud_drive);

void cloud_drive_init();
void cloud_drive_cleanup();

uint64_t cloud_drive_hash(const char* input, size_t input_size);
#endif