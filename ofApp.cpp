#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetLineWidth(3);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateZ(ofGetFrameNum() * 0.5);

	auto noise_seed_x = ofRandom(1000);
	auto noise_seed_y = ofRandom(1000);
	for (int z = -150; z <= 150; z += 10) {

		auto x = 0;
		auto noise_value_x = ofNoise(noise_seed_x, (ofGetFrameNum() + z) * 0.005);
		if (noise_value_x < 0.25) {

			x = ofMap(noise_value_x, 0, 0.25, -150, 0);
		}
		else if (noise_value_x >= 0.75) {

			x = ofMap(noise_value_x, 0.75, 1, 0, 150);
		}

		auto y = 0;
		auto noise_value_y = ofNoise(noise_seed_y, (ofGetFrameNum() + z) * 0.005);
		if (noise_value_y < 0.25) {

			y = ofMap(noise_value_y, 0, 0.25, -150, 0);
		}
		else if (noise_value_y >= 0.75) {

			y = ofMap(noise_value_y, 0.75, 1, 0, 150);
		}

		auto location = glm::vec3(x, y, z);

		ofFill();
		ofSetColor(239);
		ofDrawRectangle(location, 150, 150);

		ofNoFill();
		ofSetColor(39);
		ofDrawRectangle(location, 150, 150);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}