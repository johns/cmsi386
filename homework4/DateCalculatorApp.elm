module DateCalculatorApp exposing (..)

import Html exposing (Html, Attribute, div, input, text, p, body, h1)
import Html.Attributes exposing (id, type_, value, style)
import Html.Events exposing (onInput)
import Warmup exposing (daysBetween)

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
    body
        [style
            [ ("text-align", "center")
                , ("font", "16px Arial")
                , ("background-color", "linen")
                , ("margin", "0")
            ]
        ]
        [ h1
            [style
                [ ("font", "bold 40px Avenir")
                    , ("margin-top", "0")
                    , ("padding", "5px")
                    , ("background-color", "cyan")
                ]
            ]
            [ text "Date Calculator" ]
        , p []
            [text "From"
                , input
                [style
                    [ ("border", "2px solid grey")
                    , ("margin-left", "8px")
                    ]
                    , id "from"
                    , type_ "date"
                    , onInput UpdateInput1
                    , value dates.firstDate
                ] []
            ]
        , p []
            [text "to"
                , input
                [style
                    [("border", "2px solid grey")
                    , ("margin-left", "8px")
                    ]
                    , id "to"
                    , type_ "date"
                    , onInput UpdateInput2
                    , value dates.secondDate
                ] []
            ]
        , p []
            [text "is "
            , div
            [style
            [("font-size", "28px")]
            , id "output"
            ]
            [ text (daysBetween dates.firstDate dates.secondDate |> outputToString)]
            , text "days."
            ]
        ]
