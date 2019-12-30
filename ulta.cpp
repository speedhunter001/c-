string fun3(string s){
	string string_input_chunk = "";
	string string_output = "";
	for (int i=0; i<s.length(); i++){
		if ( s[i] == ' ' || i+1 == s.length() ){
			if ( s[i] != ' ')
				string_input_chunk = string_input_chunk + s[i];
			string_output = string_input_chunk + ' ' + string_output;
			string_input_chunk = "";
		}
		else
			string_input_chunk = string_input_chunk + s[i];
		
		

	}
	return string_output;
}
