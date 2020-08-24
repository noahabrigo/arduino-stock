const int letter_width = 6;
const int spacing = 3;
const int end_space = 6;

const bool font[1505] = {
  
  0,1,1,1,0,
  1,0,0,0,1,
  1,0,0,0,1,
  1,1,1,1,1,
  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,

  1,1,1,1,0,
  1,0,0,0,1,
  1,0,0,0,1,
  1,1,1,1,0,
  1,0,0,0,1,
  1,0,0,0,1,
  1,1,1,1,0,

  0,1,1,1,0,
  1,0,0,0,1,
  1,0,0,0,0,
  1,0,0,0,0,
  1,0,0,0,0,
  1,0,0,0,1,
  0,1,1,1,0,

  1,1,1,1,0,
  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,
  1,1,1,1,0,
  
  1,1,1,1,1,
  1,0,0,0,0,
  1,0,0,0,0,
  1,1,1,1,0,
  1,0,0,0,0,
  1,0,0,0,0,
  1,1,1,1,1,

  1,1,1,1,1,
  1,0,0,0,0,
  1,0,0,0,0,
  1,1,1,1,0,
  1,0,0,0,0,
  1,0,0,0,0,
  1,0,0,0,0,

  0,1,1,1,0,
  1,0,0,0,1,
  1,0,0,0,0,
  1,0,1,1,1,
  1,0,0,0,1,
  1,0,0,0,1,
  0,1,1,1,1,

  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,
  1,1,1,1,1,
  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,

  0,1,1,1,0,
  0,0,1,0,0,
  0,0,1,0,0,
  0,0,1,0,0,
  0,0,1,0,0,
  0,0,1,0,0,
  0,1,1,1,0,

  0,0,1,1,1,
  0,0,0,1,0,
  0,0,0,1,0,
  0,0,0,1,0,
  0,0,0,1,0,
  1,0,0,1,0,
  0,1,1,0,0,

  1,0,0,0,1,
  1,0,0,1,0,
  1,0,1,0,0,
  1,1,0,0,0,
  1,0,1,0,0,
  1,0,0,1,0,
  1,0,0,0,1,

  1,0,0,0,0,
  1,0,0,0,0,
  1,0,0,0,0,
  1,0,0,0,0,
  1,0,0,0,0,
  1,0,0,0,0,
  1,1,1,1,1,

  1,0,0,0,1,
  1,1,0,1,1,
  1,0,1,0,1,
  1,0,1,0,1,
  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,

  1,0,0,0,1,
  1,0,0,0,1,
  1,1,0,0,1,
  1,0,1,0,1,
  1,0,0,1,1,
  1,0,0,0,1,
  1,0,0,0,1,

  0,1,1,1,0,
  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,
  0,1,1,1,0,

  1,1,1,1,0,
  1,0,0,0,1,
  1,0,0,0,1,
  1,1,1,1,0,
  1,0,0,0,0,
  1,0,0,0,0,
  1,0,0,0,0,

  0,1,1,1,0,
  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,
  1,0,1,0,1,
  1,0,0,1,0,
  0,1,1,0,1,

  1,1,1,1,0,
  1,0,0,0,1,
  1,0,0,0,1,
  1,1,1,1,0,
  1,0,1,0,0,
  1,0,0,1,0,
  1,0,0,0,1,

  0,1,1,1,0,
  1,0,0,0,1,
  1,0,0,0,0,
  0,1,1,1,0,
  0,0,0,0,1,
  1,0,0,0,1,
  0,1,1,1,0,

  1,1,1,1,1,
  0,0,1,0,0,
  0,0,1,0,0,
  0,0,1,0,0,
  0,0,1,0,0,
  0,0,1,0,0,
  0,0,1,0,0,

  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,
  0,1,1,1,0,

  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,
  0,1,0,1,0,
  0,1,0,1,0,
  0,0,1,0,0,

  1,0,0,0,1,
  1,0,0,0,1,
  1,0,0,0,1,
  1,0,1,0,1,
  1,0,1,0,1,
  1,0,1,0,1,
  0,1,0,1,0,

  1,0,0,0,1,
  1,0,0,0,1,
  0,1,0,1,0,
  0,0,1,0,0,
  0,1,0,1,0,
  1,0,0,0,1,
  1,0,0,0,1,

  1,0,0,0,1,
  1,0,0,0,1,
  0,1,0,1,0,
  0,0,1,0,0,
  0,0,1,0,0,
  0,0,1,0,0,
  0,0,1,0,0,

  1,1,1,1,1,
  0,0,0,0,1,
  0,0,0,1,0,
  0,0,1,0,0,
  0,1,0,0,0,
  1,0,0,0,0,
  1,1,1,1,1,

  0,1,1,1,0,
  1,0,0,0,1,
  1,0,0,1,1,
  1,0,1,0,1,
  1,1,0,0,1,
  1,0,0,0,1,
  0,1,1,1,0,

  0,0,1,0,0,
  0,1,1,0,0,
  0,0,1,0,0,
  0,0,1,0,0,
  0,0,1,0,0,
  0,0,1,0,0,
  0,1,1,1,0,

  0,1,1,1,0,
  1,0,0,0,1,
  0,0,0,0,1,
  0,0,0,1,0,
  0,0,1,0,0,
  0,1,0,0,0,
  1,1,1,1,1,

  1,1,1,1,1,
  0,0,0,0,1,
  0,0,0,1,0,
  0,0,1,1,0,
  0,0,0,0,1,
  1,0,0,0,1,
  0,1,1,1,0,

  0,0,0,1,0,
  0,0,1,1,0,
  0,1,0,1,0,
  1,0,0,1,0,
  1,1,1,1,1,
  0,0,0,1,0,
  0,0,0,1,0,

  1,1,1,1,1,
  1,0,0,0,0,
  1,1,1,1,0,
  0,0,0,0,1,
  0,0,0,0,1,
  1,0,0,0,1,
  0,1,1,1,0,

  0,0,1,1,1,
  0,1,0,0,0,
  1,0,0,0,0,
  1,1,1,1,0,
  1,0,0,0,1,
  1,0,0,0,1,
  0,1,1,1,0,

  1,1,1,1,1,
  0,0,0,0,1,
  0,0,0,1,0,
  0,0,1,0,0,
  0,1,0,0,0,
  0,1,0,0,0,
  0,1,0,0,0,

  0,1,1,1,0,
  1,0,0,0,1,
  1,0,0,0,1,
  0,1,1,1,0,
  1,0,0,0,1,
  1,0,0,0,1,
  0,1,1,1,0,

  0,1,1,1,0,
  1,0,0,0,1,
  1,0,0,0,1,
  0,1,1,1,1,
  0,0,0,0,1,
  0,0,0,1,0,
  1,1,1,0,0,

  0,0,1,0,0,
  0,1,1,1,0,
  1,1,1,1,1,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,

  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  1,1,1,1,1,
  0,1,1,1,0,
  0,0,1,0,0,

  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,1,1,0,0,
  0,1,1,0,0,

  0,1,0,0,0,
  1,0,1,0,0,
  1,0,1,0,0,
  0,1,0,0,0,
  1,0,1,0,1,
  1,0,0,1,0,
  0,1,1,0,1,

  0,0,0,0,0,
  0,1,1,0,0,
  0,1,1,0,0,
  0,0,0,0,0,
  0,1,1,0,0,
  0,1,1,0,0,
  0,0,0,0,0,

  0,0,1,0,0,
  0,1,0,1,0,
  0,0,1,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,

  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  
  };