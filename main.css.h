const char MAIN_CSS[] PROGMEM = R"=====(
h1 {
  position: relative;
  padding: 5px 26px 5px 42px;
  background: #fff0d9;
  font-size: 20px;
  color: #2d2d2d;
  margin-left: -33px;
  line-height: 1.3;
  border-bottom: solid 3px orange;
  z-index:-2;
}

h1:before {
  position: absolute;
  content: '';
  left: -2px;
  top: -2px;
  width: 0;
  height: 0;
  border: none;
  border-left: solid 40px white;
  border-bottom: solid 79px transparent;
  z-index: -1;
}

h1:after {
  position: absolute;
  content: '';
  right: -3px;
  top: -7px;
  width: 0;
  height: 0;
  border: double;
  border-left: solid 40px transparent;
  border-bottom: solid 79px white;
  z-index: -1;
}

th {
  padding: 5px;
  margin: 10px;
  color: #2d2d2d;
  background: #fff0d9;
}
td {
  padding: 10px;
  margin: 10px;
  background: #FFFFDD;
}

input {
  background: #fff0d9;
  font-size: 20px;
  color: #2d2d2d;
}

.box8 {
    padding: 0.5em 1em;
    margin: 2em 0;
    color: #232323;
    background: #fff8e8;
    border-left: solid 10px #ffc06e;
}
.box8 p {
    margin: 0; 
    padding: 0;
}
)=====";
