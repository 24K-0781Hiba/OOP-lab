#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MediaFile {
protected:
    string filePath;
    double fileSize;

public:
    MediaFile(const string& path, double size)
        : filePath(path), fileSize(size) {}

    virtual void play() {
        cout << "Playing media file: " << filePath << endl;
    }

    virtual void stop() {
        cout << "Stopping media file: " << filePath << endl;
    }

    virtual void display() const {
        cout << "File Path: " << filePath << ", Size: " << fileSize << " MB" << endl;
    }

    virtual ~MediaFile() = default;
};

//intermediate class
class VisualMedia : virtual public MediaFile {
protected:
    int resolutionWidth;
    int resolutionHeight;

public:
    VisualMedia(const string& path, double size, int width, int height)
        : MediaFile(path, size), resolutionWidth(width), resolutionHeight(height) {}

    void display() const override {
        MediaFile::display();
        cout << "Resolution: " << resolutionWidth << "x" << resolutionHeight << endl;
    }
};

//also an intermediate class
class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;

public:
    AudioMedia(const string& path, double size, int rate)
        : MediaFile(path, size), sampleRate(rate) {}

    void display() const override {
        MediaFile::display();
        cout << "Sample Rate: " << sampleRate << " Hz" << endl;
    }
};

//derived from visual and audio
class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(const string& path, double size, int width, int height, int rate)
        : MediaFile(path, size),
          VisualMedia(path, size, width, height),
          AudioMedia(path, size, rate) {}

    void play() override {
        cout << "Playing video file: " << filePath << endl;
    }

    void stop() override {
        cout << "Stopping video file: " << filePath << endl;
    }

    void display() const override {
        VisualMedia::display();
        cout << "Sample Rate: " << sampleRate << " Hz" << endl;
    }
};

//derived from visual
class ImageFile : public VisualMedia {
public:
    ImageFile(const string& path, double size, int width, int height)
        : MediaFile(path, size), VisualMedia(path, size, width, height) {}

    void play() override {
        cout << "Cannot play image file: " << filePath << endl;
    }

    void stop() override {
        cout << "Cannot stop image file: " << filePath << endl;
    }
};

//derived from audio
class AudioFile : public AudioMedia {
public:
    AudioFile(const string& path, double size, int rate)
        : MediaFile(path, size), AudioMedia(path, size, rate) {}

    void play() override {
        cout << "Playing audio file: " << filePath << endl;
    }

    void stop() override {
        cout << "Stopping audio file: " << filePath << endl;
    }
};

int main() {
    VideoFile video("video.mp4", 250.5, 1920, 1080, 48000);
    ImageFile image("image.jpg", 5.2, 800, 600);
    AudioFile audio("audio.mp3", 10.0, 44100);

    vector<MediaFile*> mediaLibrary = {&video, &image, &audio};
    for (auto media : mediaLibrary) {
        cout << "----------------------------------------" << endl;
        media->display();
        media->play();
        media->stop();
        cout << "----------------------------------------" << endl;
    }
    return 0;
}
