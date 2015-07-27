%Designed by Adam Ribblett
function varargout = nanohubGUI_sec008_team24(varargin)
% NANOHUBGUI_SEC008_TEAM24 MATLAB code for nanohubGUI_sec008_team24.fig
%      NANOHUBGUI_SEC008_TEAM24, by itself, creates a new NANOHUBGUI_SEC008_TEAM24 or raises the existing
%      singleton*.
%
%      H = NANOHUBGUI_SEC008_TEAM24 returns the handle to a new NANOHUBGUI_SEC008_TEAM24 or the handle to
%      the existing singleton*.
%
%      NANOHUBGUI_SEC008_TEAM24('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in NANOHUBGUI_SEC008_TEAM24.M with the given input arguments.
%
%      NANOHUBGUI_SEC008_TEAM24('Property','Value',...) creates a new NANOHUBGUI_SEC008_TEAM24 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before nanohubGUI_sec008_team24_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to nanohubGUI_sec008_team24_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help nanohubGUI_sec008_team24

% Last Modified by GUIDE v2.5 19-Apr-2013 03:28:37

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @nanohubGUI_sec008_team24_OpeningFcn, ...
                   'gui_OutputFcn',  @nanohubGUI_sec008_team24_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before nanohubGUI_sec008_team24 is made visible.
function nanohubGUI_sec008_team24_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to nanohubGUI_sec008_team24 (see VARARGIN)

% Choose default command line output for nanohubGUI_sec008_team24
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);
%Load Image on Title Screen
%Opening function
axes(handles.axes1)
imshow('nanohubGUI.jpg');



% UIWAIT makes nanohubGUI_sec008_team24 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = nanohubGUI_sec008_team24_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton9.
function pushbutton9_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close
citationGUI_sec008_team24

% --- Executes on button press in pushbutton10.
function pushbutton10_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close
GUI1

% --- Executes on button press in pushbutton11.
function pushbutton11_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton11 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close
overviewGUI_sec008_team24

% --- Executes on button press in pushbutton12.
function pushbutton12_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton12 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close
