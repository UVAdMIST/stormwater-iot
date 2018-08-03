function Decoder(bytes) {

  var distance = (bytes[0] << 8) | bytes[1];

  return {
    distance: distance 
  }
}