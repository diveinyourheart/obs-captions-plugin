#ifndef OBS_GOOGLE_CAPTION_PLUGIN_CAPTIONRESULT_H
#define OBS_GOOGLE_CAPTION_PLUGIN_CAPTIONRESULT_H

#ifndef _CHRONO_
#include <chrono>
#endif // !_CHRONO_


using namespace std;

/*
{
  "result": [
    {
      "alternative": [
	{
	  "transcript": "Hello world",
	  "confidence": 0.9
	}
      ],
      "final": true,
      "stability": 0.8
    }
  ],
  "result_index": 0
}
*/

struct CaptionResult {

	int index = 0;
	bool final = false;
	double stability = 0.0;
	string caption_text;
	string raw_message;

	std::chrono::steady_clock::time_point first_received_at;
	std::chrono::steady_clock::time_point received_at;

	CaptionResult() {};

	CaptionResult(
		int index,
		bool final,
		double stability,
		string caption_text,
		string raw_message,
		std::chrono::steady_clock::time_point first_received_at,
		std::chrono::steady_clock::time_point received_at
	) :
		index(index),
		final(final),
		stability(stability),
		caption_text(caption_text),
		raw_message(raw_message),
		first_received_at(first_received_at),
		received_at(received_at) {
	}
};
#endif // !OBS_GOOGLE_CAPTION_PLUGIN_CAPTIONRESULT_H
