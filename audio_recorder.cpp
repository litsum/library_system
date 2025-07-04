#include "audio_recorder.h"

AudioRecorder::AudioRecorder() {
    session = new QMediaCaptureSession();
    recorder = new QMediaRecorder();
    audioInput = new QAudioInput();

    session->setAudioInput(audioInput);
    session->setRecorder(recorder);

    // 设置录音参数（可以根据需要调整）
    QMediaFormat mediaFormat;
    mediaFormat.setFileFormat(QMediaFormat::FileFormat::Wave); // 设置文件格式为 WAV
    recorder->setMediaFormat(mediaFormat);

    recorder->setAudioSampleRate(44100);      // 采样率 44100 Hz
    recorder->setAudioChannelCount(2);        // 通道数 2
    recorder->setAudioBitRate(128000);        // 比特率 128000
    recorder->setQuality(QMediaRecorder::NormalQuality); // 品质
}

QString AudioRecorder::startRecording() {
    // 设置输出文件路径为项目文件夹下的 "recording.wav"
    QString projectDir = QDir::currentPath();
    recordingFilePath = projectDir + "/recording.wav";

    recorder->setOutputLocation(QUrl::fromLocalFile(recordingFilePath));

    // 如果文件已存在，先删除
    if (QFile::exists(recorder->outputLocation().toLocalFile())) {
        QFile::remove(recorder->outputLocation().toLocalFile());
    }

    recorder->record();

    return recordingFilePath;
}

void AudioRecorder::stopRecording() {
    recorder->stop();
}

QString AudioRecorder::getRecordingFilePath() const {
    return recordingFilePath;
}
