//this function is based on https://community.particle.io/t/reading-spark-variables-with-your-own-html-file/4148
function readPhotoresistor()
{
  document.getElementById('light').innerHTML = "Waiting for result...";
  document.getElementById('timeStamp').innerHTML = "";

  requestURL = "https://api.particle.io/v1/devices/3e0031000847343133353336/analogValue?access_token=4ed978c8d44ee74e0da0a2e08db5dcd401ce9958";
  $.getJSON(requestURL, function(json) {
                 document.getElementById("light").innerHTML = "Analog Value: " + json.result;
                 document.getElementById("timeStamp").innerHTML = "Time of Reading: " + json.coreInfo.last_heard;
                 });
}
