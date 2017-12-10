module DateCalculatorApp exposing (..)

import Html exposing (Html, Attribute, div, input, text, p, body, h1)
import Html.Attributes exposing (id, type_, value, style)
import Html.Events exposing (onInput)
import Warmup exposing (daysBetween)

main : Program Never Dates Msg
main =
  Html.beginnerProgram { model = dates, view = view, update = update }

type alias Dates = {
    firstDate: String,
    secondDate: String
}
type Msg = UpdateInput1 String | UpdateInput2 String

dates : Dates
dates = { firstDate = "", secondDate = "" }

update : Msg -> Dates -> Dates
update msg dates =
  case msg of
    UpdateInput1 input -> { dates | firstDate = input }
    UpdateInput2 input -> { dates | secondDate = input }

outputToString : Result String Int -> String
outputToString toFormat =
  case toFormat of
    Err msg -> ""
    Ok output -> toString output


view : Dates -> Html Msg
view dates =
    body [style [("textAlign", "center"), ("font","16px Arial"), ("background-color","linen"), ("margin","0")]]
        [ h1 [style [("font","bold 40px Avenir"), ("background-color","cyan"), ("margin-top","0"), ("padding","5px")]]
            [text "Date Calculator"]
        , p [] [text "From", input [style [("border", "2px solid grey"),("margin-left", "8px")], type_ "date", id "from", onInput UpdateInput1, value dates.firstDate] []]
        , p [] [text "to", input [style [("border", "2px solid grey"),("margin-left", "8px")], type_ "date", id "to", onInput UpdateInput2, value dates.secondDate] []]
        , text "is"
        , p [] [ text (daysBetween dates.firstDate dates.secondDate |> outputToString)]
        , text "days."
        ]
