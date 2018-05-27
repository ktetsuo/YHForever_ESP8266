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
                Button1
                <ul>
                    <li><a href="javascript:void(0);" onclick="OnButton(1,1);">Send</a></li>
                    <li><a href="javascript:void(0);" onclick="OnButton(1,2);">Learn</a></li>
                </ul>
            </li>
            <li>
                Button2
                <ul>
                    <li><a href="javascript:void(0);" onclick="OnButton(2,1);">Send</a></li>
                    <li><a href="javascript:void(0);" onclick="OnButton(2,2);">Learn</a></li>
                </ul>
            </li>
        </ul>
    </div>
    <script type="text/javascript">
        function OnButton(id, val) {
            var xhr = new XMLHttpRequest();
            xhr.open("GET", `button?id=${id}&val=${val}`);
            xhr.send();
        }
    </script>
</body>

</html>
)=====";
