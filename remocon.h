const char REMOCON_HTML[] PROGMEM = R"=====(
<!DOCTYPE HTML>
<html>

<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="nefry_css">
    <title>YHRemocon</title>
</head>

<body>
    <div>
        <h1>YHRemocon</h1>
        <ul>
            <li>
                <a href="javascript:void(0);" onclick="OnButton1();">Button1</a>
            </li>
            <li>
                <a href="javascript:void(0);" onclick="OnButton2();">Button2</a>
            </li>
        </ul>
    </div>
    <script type="text/javascript">
        function OnButton1() {
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "button?id=1&val=1");
            xhr.send();
        }
        function OnButton2() {
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "button?id=2&val=1");
            xhr.send();
        }
    </script>
</body>

</html>
)=====";
