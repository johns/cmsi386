module Warmup exposing (..)


change : Int -> Result String ( Int, Int, Int, Int )
change num =
    if num < 0 then
        Err "amount cannot be negative"
    else
        Ok (num // 25, num % 25 // 10, num % 25 % 10 // 5, num % 25 % 10 % 5)
