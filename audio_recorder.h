#ifndef AUDIO_RECORDER_H
#define AUDIO_RECORDER_H
#include <QApplication>
#include <QMediaCaptureSession>
#include <QMediaRecorder>
#include <QAudioInput>
#include <QString>
#include <QDir>
#include <QtMultimedia>

class AudioRecorder {
public:
    AudioRecorder();
    QString startRecording();
    void stopRecording();
    QString getRecordingFilePath() const;

private:
    QMediaCaptureSession* session;
    QMediaRecorder* recorder;
    QAudioInput* audioInput;
    QString recordingFilePath;
};
#endif // AUDIO_RECORDER_H
